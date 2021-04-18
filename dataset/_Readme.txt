******************************************************************************************
*        DIGITALES LiDAR GELÄNDEMODELL VON DEUTSCHLAND, 1 Bogensekunde, Version 1        *
******************************************************************************************


* Zusammengestellt und resampled von Sonny
* E-Mail:  sonnyy7@gmail.com
* Twitter: https://twitter.com/SonnyLidarDTMs
* Website: https://data.opendataportal.at/dataset/dtm-germany
* Alternativ gibt es auf der Website das Geländemodell auch noch in anderen Gitterweiten.

======================================================================================


Dieses digitale Höhenmodell (hier ein digitales Geländemodell DGM - im Gegensatz zu einem digitalen Oberflächenmodell DOM) verwendet per präziser LiDAR Technik erzeugte Geländemodelle als Datengrundlage. Diese wurden mittels Airborne Laserscan (ALS)-Befliegungen vermessen. Deshalb der große Vorteil dieses Modells: Die Abweichungen der Geländehöhen in diesem Modell im Vergleich zu den Laserhöhen der Quelldaten, speziell in bergigem und hügeligem Terrain, sind deutlich geringer als jene der verbreiteten SRTM-Kacheln.

Für das vollständige Auffüllen der Gradkacheln außerhalb der Landes-Quelldaten habe ich die für das jeweilige Gebiet aktuell besten Opendata-DGMs verwendet. Diese stammen entweder ebenfalls aus LiDAR-Vermessungen. Oder ansonsten Höhendaten der SRTM-Mission https://de.wikipedia.org/wiki/SRTM-Daten (SRTM Version 3.0 Global 1" DTMs, Download: https://dwtkns.com/srtm30m/ ) oder auch von Viewfinder Panoramas by Jonathan de Ferranti (1" DTMs, http://viewfinderpanoramas.org/dem3.html ). Alle Einzel-Dateien wurden neben- bzw. übereinander gelegt und mit 1" (1 Bogensekunde = 1/3600 Grad, entspricht in etwa 20 x 30 Meter) bzw. 3" (3 Bogensekunden = 3/3600 Grad, entspricht in etwa 60 x 90 Meter) resampled.

Als Dateiformat (.hgt) wurde das weltweit verbreitete SRTM Format gewählt. Jede Höhenkacheldatei (.hgt) deckt dabei genau einen Bereich von 1 x 1° ab, deren Bereich sich automatisch aus dem Dateinamen ergibt. Der Dateiname bezeichnet die südwestliche Ecke, z.b. "N47E014.hgt" deckt den Bereich der geographischen Breite von N47° bis N48° und einer geographischen Länge von E14° bis E15° ab.


PROJEKTION und DATEIFORMAT
**************************

- Koordinatenreferenzsystem: EPSG:4326
- Geodätisches Datum: WGS 84
- Koordinatensystem: Geographische Grad
- 1 Dateikachel besteht genau aus 3601 x 3601 (1" Modell) bzw. 1201 x 1201 (3" Modell) Höhenpixel
- Horizontale Auflösung: 1 Bogensekunde = 1/3600 Grad = 0.000277778 Grad (1" Modell) bzw. 3 Bogensekunden = 3/3600 Grad = 0.000833333 Grad (3" Modell)
- Vertikales Datum: Unverändertes Höhen-Bezugssystem der Quelldaten. Normalerweise das nationale, auf Höhe über dem mittleren Meeresspiegel basierende System
- Vertikale Auflösung: 1 Meter
- Byteorder: Motorola (Big Endian = most significant byte first)
- Dateigröße einer Kachel: 25934402 Bytes (1" Modell) bzw. 2884802 Bytes (3" Modell)


QUELLEN und LIZENZ
******************

Dieses Geländemodell ist OFFEN, FREI und KOSTENLOS verwendbar, unterliegt aber der LIZENZ: Creative Commons Namensnennung 4.0 (CC BY 4.0), siehe https://creativecommons.org/licenses/by/4.0/deed.de

Ihr dürft daher dessen Daten vervielfältigen, verbreiten, öffentlich zugänglich machen, auch kommerziell nutzen, sowie Abwandlungen und Bearbeitungen des Inhalts anfertigen. Ihr solltet bei Verwendung meinen Namen (Sonny), sowie die Website (siehe ganz oben) erwähnen, herzlichen Dank!


Für das Geländemodell dieses Gebiets wurden folgende FREIE Opendata Quelldaten verwendet:


- Bayerische Vermessungsverwaltung (www.geodaten.bayern.de): DTM 50 Meter
https://opendata.bayern.de/detailansicht/datensatz/digitales-gelaendemodell-50-m-gitterweite

- Senatsverwaltung für Stadtentwicklung und Umwelt Berlin: ATKIS® DTM 1 Meter
http://www.stadtentwicklung.berlin.de/geoinformation/geodateninfrastruktur/de/geodienste/atom.shtml
Für die Verwendung der Daten gelten folgende Nutzungsbestimmungen: http://www.stadtentwicklung.berlin.de/geoinformation/download/nutzIII.pdf

- Land Brandenburg, Landesvermessung und Geobasisinformation Brandenburg (LGB): DTM 1 Meter
https://geoportal.brandenburg.de/detailansichtdienst/render?view=gdibb&url=https://geoportal.brandenburg.de/gs-json/xml?fileid=488a2b53-564f-43eb-88ec-0d87bb43ed20
https://geobasis-bb.de/lgb/de/startseite/geodaten/3d-produkte/gelaendemodell/

- Freie und Hansestadt Hamburg, Landesbetrieb Geoinformation und Vermessung, 2014 : DTM 10 Meter
http://suche.transparenz.hamburg.de/dataset/digitales-hohenmodell-hamburg-dgm-101
License: Datenlizenz Deutschland Namensnennung 2.0

- Land Nordrhein-Westfalen (2017), DTM 1 Meter
https://open.nrw/de/dataset/0c6796e5-9eca-4ae6-8b32-1fcc5ae5c481bkg

- Landesamt für Vermessung und Geobasisinformation Rhineland-Palatinate: DTM 25 Meter (DGM25)
http://www.lvermgeo.rlp.de/index.php?id=opendata
©GeoBasis-DE / LVermGeoRP 2016, dl-de/by-2-0, http://www.lvermgeo.rlp.de [data modified]

- Staatsbetrieb Geobasisinformation und Vermessung Sachsen : DTM 2 Meter
https://www.geodaten.sachsen.de/digitale-hoehenmodelle-3994.html

- Landesamt für Vermessung und Geoinformation Sachsen-Anhalt: DTM 5 Meter
https://www.lvermgeo.sachsen-anhalt.de/de/kostenfreie_geobasisdaten_lvermgeo.html

- Freistaat Thüringen, Landesamt für Vermessung und Geoinformation: DTM 1 meters (2014-2019), DTM 2 meters (2010-2013)
http://www.geoportal-th.de/de-de/downloadbereiche/downloadoffenegeodatenth%C3%BCringen/downloadh%C3%B6hendaten.aspx

- NASA: SRTM Version 3.0 Global 1" DTMs
https://dwtkns.com/srtm30m/

- Viewfinder Panoramas by Jonathan de Ferranti: 1" DTMs
http://viewfinderpanoramas.org/dem3.html
Jonathan de Ferranti permitted me to use his elevation data within my DTM using the CC BY 4.0 license terms.

- Gebiete außerhalb der Landes-Quelldaten: siehe Datei "_Datasources.txt" in den Ressourcen "DTM Europe 1" oder "DTM Europe 3"
https://data.opendataportal.at/dataset/dtm-europe


======================================================================================
======================================================================================



*********************************************************************************
*        DIGITAL LiDAR TERRAIN MODEL OF GERMANY, 1 arcsecond, Version 1         *
*********************************************************************************


* Compiled and resampled by Sonny
* E-Mail:  sonnyy7@gmail.com
* Twitter: https://twitter.com/SonnyLidarDTMs
* Website: https://data.opendataportal.at/dataset/dtm-germany
* Alternatively you can also find the Terrain model with other Grid spaces on the Website.

======================================================================================

This Digital Elevation Model (exactly: Digital Terrain Model DTM - in contrast to Digital surface model DSM) is based on precise LiDAR elevation sources. They have been surveyed using the method of Airborne Laserscan (ALS). The difference of my model's elevations, especially in rocky terrain, are significant less compared to those of the popular original SRTM-datasets.

The areas outside of the country's source data are filled with the best available Opensource elevation data of the particular region. Either these are based on LiDAR data too. Or otherwise from the SRTM-Mission https://en.wikipedia.org/wiki/Shuttle_Radar_Topography_Mission (SRTM Version 3.0 Global 1" DTMs, Download: https://dwtkns.com/srtm30m/ ) or also from Viewfinder Panoramas by Jonathan de Ferranti (1" DTMs, http://viewfinderpanoramas.org/dem3.html ). The source files have been aranged next and above each other and resampled with a sample spacing of 1" (1 arcseconds = 1/3600 degree, equals about 20 x 30 meters) or 3" (3 arcseconds = 3/3600 degree, equals about 60 x 90 meters).

I used the worldwide popular file format of the SRTM datasets (.hgt files). Each elevation file (.hgt) represends exactly 1 x 1°, which could automatically derived from the filename. The filename specifies the southwest corner, e.g. "N47E014.hgt" represends an area from N47° to N48° latitude and E14° to E15° longitude.


PROJECTION and FILEFORMAT
*************************

- Coordinate Reference System: EPSG:4326 
- Geodetic date: WGS 84
- Coordinate system: geographic degrees
- 1 file contains 3601 x 3601 (1" model) or 1201 x 1201 (3" model) elevation pixels
- Horizontal resolution: 1 arcsecond = 1/3600 degree = 0.000277778 degree (1" model) or 3 arcseconds = 3/3600 degree = 0.000833333 degree (3" model)
- Vertical datum: Unmodified elevation system of the source data. Usually the national elevation system, based on Height above mean sea level
- Vertical resolution: 1 meter
- Byteorder: Motorola (Big Endian = most significant byte first)
- Filesize of one file: 25934402 Bytes (1" model) or 2884802 Bytes (3" model)


SOURCES und LICENCE
*******************

This Terrain Model is OPEN, FREE and WITHOUT CHARGE. But it is licensed using the following LICENCE: Creative Commons Attribution 4.0 (CC BY 4.0),
look at https://creativecommons.org/licenses/by/4.0/deed.en

You are allowed to copy, redistribute the material in any medium or format as well as remix, transform, and build upon the material for any purpose, even commercially. Please mention my name (Sonny) and the Website (see at the top), thank you!


To create the terrain model of this territory I used the following FREE Opendata sources:


- Bayerische Vermessungsverwaltung (www.geodaten.bayern.de): DTM 50 Meter
https://opendata.bayern.de/detailansicht/datensatz/digitales-gelaendemodell-50-m-gitterweite

- Senatsverwaltung für Stadtentwicklung und Umwelt Berlin: ATKIS® DTM 1 Meter
http://www.stadtentwicklung.berlin.de/geoinformation/geodateninfrastruktur/de/geodienste/atom.shtml
Für die Verwendung der Daten gelten folgende Nutzungsbestimmungen: http://www.stadtentwicklung.berlin.de/geoinformation/download/nutzIII.pdf

- Land Brandenburg, Landesvermessung und Geobasisinformation Brandenburg (LGB): DTM 1 Meter
https://geoportal.brandenburg.de/detailansichtdienst/render?view=gdibb&url=https://geoportal.brandenburg.de/gs-json/xml?fileid=488a2b53-564f-43eb-88ec-0d87bb43ed20
https://geobasis-bb.de/lgb/de/startseite/geodaten/3d-produkte/gelaendemodell/

- Freie und Hansestadt Hamburg, Landesbetrieb Geoinformation und Vermessung, 2014 : DTM 10 Meter
http://suche.transparenz.hamburg.de/dataset/digitales-hohenmodell-hamburg-dgm-101
License: Datenlizenz Deutschland Namensnennung 2.0

- Land Nordrhein-Westfalen (2017), DTM 1 Meter
https://open.nrw/de/dataset/0c6796e5-9eca-4ae6-8b32-1fcc5ae5c481bkg

- Landesamt für Vermessung und Geobasisinformation Rhineland-Palatinate: DTM 25 Meter (DGM25)
http://www.lvermgeo.rlp.de/index.php?id=opendata
©GeoBasis-DE / LVermGeoRP 2016, dl-de/by-2-0, http://www.lvermgeo.rlp.de [data modified]

- Staatsbetrieb Geobasisinformation und Vermessung Sachsen : DTM 2 Meter
https://www.geodaten.sachsen.de/digitale-hoehenmodelle-3994.html

- Landesamt für Vermessung und Geoinformation Sachsen-Anhalt: DTM 5 Meter
https://www.lvermgeo.sachsen-anhalt.de/de/kostenfreie_geobasisdaten_lvermgeo.html

- Freistaat Thüringen, Landesamt für Vermessung und Geoinformation: DTM 1 meters (2014-2019), DTM 2 meters (2010-2013)
http://www.geoportal-th.de/de-de/downloadbereiche/downloadoffenegeodatenth%C3%BCringen/downloadh%C3%B6hendaten.aspx

- NASA: SRTM Version 3.0 Global 1" DTMs
https://dwtkns.com/srtm30m/

- Viewfinder Panoramas by Jonathan de Ferranti: 1" DTMs
http://viewfinderpanoramas.org/dem3.html
Jonathan de Ferranti permitted me to use his elevation data within my DTM using the CC BY 4.0 license terms.

- Areas outside of the country's source data: open file "_Datasources.txt" within the ressources "DTM Europe 1" or "DTM Europe 3"
https://data.opendataportal.at/dataset/dtm-europe
