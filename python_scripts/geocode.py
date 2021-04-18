#!/usr/bin/env python3

import sys
from geopy.geocoders import Nominatim
# docs: https://geopy.readthedocs.io/en/stable/#module-geopy.geocoders

if __name__ == "__main__":
    geolocator = Nominatim(user_agent="minfo_hackathon")
    for query in sys.argv:
        location = geolocator.geocode(str(query))
        if location:
            print(location.longitude, location.latitude)

