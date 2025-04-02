# The Great Frog Munch

## Projektbeschreibung

**The Great Frog Munch** wurde im Rahmen der Vorlesung **Programmieren in C++** an der Hochschule für Wirtschaft und Recht entwickelt. Ziel des Spiels ist es, so viele Punkte wie möglich zu sammeln, indem man den Frosch am unteren Rand des Bildschirms bewegt und herunterfallende Gegenstände auffängt.

## Spielmechanik

- **Punkte sammeln:**
- Fangen Sie Kekse, Eis und Kuchen, um jeweils einen Punkt zu erhalten.

- **Leben verlieren:**
- Vermeiden Sie das Auffangen von Sägen, Sellerie, Kothaufen, Äxten oder Kakteen, da Sie dadurch ein Leben verlieren.

- **Leben gewinnen:**
- Sie starten mit 5 Leben und können zusätzliche Leben gewinnen, indem Sie Fliegen fangen.

- **Spielende:**
- Wenn Sie eine Bombe erwischen, ist das Spiel sofort vorbei.

## Kompilierung und Ausführung

Das Spiel lässt sich einfach kompilieren und starten. Führen Sie dazu folgende Befehle im Root-Ordner aus:

```bash
cmake -B build
cmake --build build
./build/bin/main
```

## Grafiken

Für die Erstellung der Spielfiguren und -gegenstände wurden KI-generierte Bilder verwendet. Die Bilder wurden mithilfe von DeepAI erstellt.
