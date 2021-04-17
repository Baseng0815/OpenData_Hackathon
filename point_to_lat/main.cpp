#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

const sf::Vector2f bottom_left    = { 8.716f, 50.768f };
const sf::Vector2f top_right      = { 8.820f, 50.860f };

sf::Vector2f mouse_to_lat(int mx, int my, int wx, int wy)
{
    /* make mouse start at bottom instead of top */
    my = wy - my;

    double lon_per_pixel = (top_right.x - bottom_left.x) / (double)wx;
    double lat_per_pixel = (top_right.y - bottom_left.y) / (double)wy;

    return sf::Vector2f(lon_per_pixel * mx + bottom_left.x,
                        lat_per_pixel * my + bottom_left.y);
}

int main(int argc, char *argv[])
{
    /* map texture */
    sf::Texture map_texture;
    map_texture.loadFromFile("map.png");
    sf::Sprite map_sprite;
    map_sprite.setTexture(map_texture);

    /* lines */
    std::vector<sf::Vertex> vertex_array;
    sf::CircleShape         va_point;
    va_point.setRadius(3.f);
    va_point.setOrigin(3.f, 3.f);
    va_point.setFillColor(sf::Color::Red);

    sf::RenderWindow window(sf::VideoMode(map_texture.getSize().x,
                                          map_texture.getSize().y),
                            "SFML Window", sf::Style::None);
    window.setPosition(sf::Vector2i(960 - window.getSize().x / 2,
                                    540 - window.getSize().y / 2));

    int num_points = 0;

    while (window.isOpen()) {

        /* updating */
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case event.KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    break;

                case event.Closed:
                    window.close();
                    break;

                case event.MouseButtonPressed: {
                    int mx = event.mouseButton.x;
                    int my = event.mouseButton.y;

                    /* add to map */
                    sf::Vertex vertex;
                    vertex.color = sf::Color::Red;
                    vertex.position = sf::Vector2f { mx, my };
                    vertex_array.emplace_back(vertex);

                    /* calculate lat/lon and print */
                    sf::Vector2f lat = mouse_to_lat(mx, my,
                                                    window.getSize().x,
                                                    window.getSize().y);
                    std::cout << lat.x << " " << lat.y << std::endl;
                    break;
                }

                default:
                    break;
            }
        }

        /* drawing */
        window.clear(sf::Color::Black);

        window.draw(map_sprite);
        window.draw(&vertex_array[0], vertex_array.size(), sf::LinesStrip);

        for (const sf::Vertex &v : vertex_array) {
            va_point.setPosition(v.position);
            window.draw(va_point);
        }

        window.display();
    }

    return num_points;
}
