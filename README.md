# The Great Frog Munch

## Projektbeschreibung

**The Great Frog Munch** wurde im Rahmen der Vorlesung **Programmieren in C++** an der Hochschule für Wirtschaft und Recht entwickelt. Ziel des Spiels ist es, so viele Punkte wie möglich zu sammeln, indem man den Frosch am unteren Rand des Bildschirms bewegt und herunterfallende Gegenstände auffängt.

Den Code kannst du dir auch auf [GitHub](https://github.com/MarlenKoch/cppAbgabe.git) anschauen.

## Spielmechanik

- **Punkte sammeln:** Fange Kekse, Eis und Kuchen, um jeweils einen Punkt zu erhalten.

- **Leben verlieren:** Vermeide das Auffangen von Sägen, Sellerie, Kothaufen, Äxten oder Kakteen, da du dadurch ein Leben verlierst.

- **Leben gewinnen:** Du startest mit 5 Leben und kannst zusätzliche Leben gewinnen, indem du Fliegen fängst.

- **Spielende:** Erwischst du eine Bombe, ist das Spiel vorbei.

## Kompilierung und Ausführung

Das Spiel lässt sich durch das ausführen der folgenden Befehle kompilieren:

```bash
cmake -B build
cmake --build build
./build/bin/main
```
Alle Befehle sollten aus dem Ordner ausgeführt werden, in dem sich diese Readme befindet, da die Pfade zu den assets relativ angegeben sind. Im Ordner prebuild findest du einen Prebuild des Spiels. Führe dazu folgenden Befehl aus: 

```bash
./prebuild/bin/main
```
Der Prebuild wurde auf einem MacBook Pro M2 (macOS 15.3.2 (24D81), ARM-based) mit cmake Version 3.31.6 erstellt. 

## Grafiken und Schriftart

Für die Erstellung der Spielfiguren und -gegenstände wurden KI-generierte Bilder verwendet. Die Bilder wurden mithilfe von DeepAI erstellt. Als Schriftart wurde Chatkids von Khurasan verwendet.
