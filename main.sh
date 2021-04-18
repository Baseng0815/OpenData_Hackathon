#!/bin/bash

# usage examples:
# ./main.sh
# ./main.sh -s mein_höhenprofil.png
# ./main.sh "hauptbahnhof, marburg" "lahnberge"
# ./main.sh -s mein_höhenprofil.png "hauptbahnhof, marburg" "lahnberge"

cur="$(dirname $0)" # current directory

visualize_cmd="$cur/python_scripts/visualize.py"
while [[ "$1" == -* ]]; do
    case "$1" in
        -s|--save)
            shift
            visualize_cmd="$cur/python_scripts/visualize.py -s $1"
            ;;
        -*)
            echo "Flag '$1' not supported"
            ;;
    esac
    shift
done

points=""
if [ $# -eq 0 ]; then
    points="$("$cur/point_to_lat/point_to_lat")"
else
    points="$("$cur/python_scripts/geocode.py" "$@")"
fi

# at least two points have to be selected, otherwise exit
if [ "$(echo "$points" | wc -l)" -lt 2 ]; then
    exit
fi

echo "$points" | \
    "$cur/python_scripts/lat_to_height.py" | \
    $visualize_cmd

