#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

const std::string filename = "../N50E008.hgt";
uint16_t *data;
const int size = 3601;
const float degreesPerPixel = 1 / 60.f;

const float offsets[2] = {8, 50};

struct Vector {
  float lon, lat;

  float length() const { return sqrt(lon * lon + lat * lat); }

  void normalize() {
    float length = this->length();

    lon /= length;
    lat /= length;
  }

  Vector operator+(const Vector &other) const {
    return Vector{lon + other.lon, lat + other.lat};
  }

  Vector operator-(const Vector &other) const {
    return Vector{lon - other.lon, lat - other.lat};
  }

  Vector operator-() const { return Vector{-lon, -lat}; }
};

static Vector operator*(float value, const Vector &vec) {
  return Vector{value * vec.lon, value * vec.lat};
}

static float operator*(const Vector &v1, const Vector &v2) {
  return v1.lon * v2.lon + v1.lat * v2.lat;
}

uint16_t swapBytes(uint16_t number) {
  uint8_t lower = number & 0x00ff;
  uint8_t higher = (number & 0xff00) >> 8;

  return higher | (lower << 8);
}

uint16_t *readData(const std::string &filename) {
  FILE *file = fopen(filename.c_str(), "rb");

  int length = size * size;

  uint16_t *data = new uint16_t[length];
  fread(data, sizeof(uint16_t), length, file);

  for (int i = 0; i < length; i++) {
    uint16_t value = data[i];
    data[i] = swapBytes(value);
  }

  return data;
}

std::vector<Vector> getPoints(Vector p1, Vector p2) {
  Vector currentPosition = p1;

  Vector dv = p2 - p1;
  Vector ndv = 1 / dv.length() * dv;

  std::vector<Vector> points;
  points.push_back(currentPosition);

  while ((currentPosition - p1).length() <= dv.length()) {
    float dx = currentPosition.lon - (dv.lon > 0 ? floor(currentPosition.lon)
                                                 : ceil(currentPosition.lon));
    float dy = currentPosition.lat - (dv.lat > 0 ? floor(currentPosition.lat)
                                                 : ceil(currentPosition.lat));

    // abs(dx) > abs(dy)
    float factor = 0;
    if ((dx - dy) > 0) {
      factor = dx / ndv.lon;
    } else {
      factor = dy / ndv.lat;
    }

    currentPosition = currentPosition + factor * ndv;
    points.push_back(currentPosition);
  }

  return points;
}

uint16_t getHeight(Vector point) {
  int x = floor((point.lon - offsets[0]) / degreesPerPixel);
  int y = floor((point.lat - offsets[1]) / degreesPerPixel);

  return data[y * size + x];
}

int main(int, char **) {
  data = readData(filename);

  Vector p1, p2;

  std::cin >> p1.lon;
  std::cin >> p1.lat;

  do {
    std::cin >> p2.lon;
    std::cin >> p2.lat;

    std::vector<Vector> points = getPoints(p1, p2);
    for (const auto& point : points) {
        int height= getHeight(point);
        std::cout << height << " ";
    }

    p1 = p2;
  } while (std::cin.peek() != (int)';');
}
