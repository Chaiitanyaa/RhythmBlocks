# 🎵 RhythmBeats: Music Composition with Cubes

**RhythmBeats** is a tangible music composition tool where users place physical cubes labeled with musical notes and instrument types onto an 8-slot board. Using a webcam and a Teachable Machine model, RhythmBeats detects cube types and locations, then plays the corresponding musical sequence in your browser.

---

## 🚀 Features

- 🎥 **Teachable Machine Integration** – Classifies cubes using webcam video.
- 🔌 **Arduino Slot Detection** – Detects physical placement of cubes via buttons.
- 🔊 **Browser-Based Sound Playback** – Plays notes through your browser using local `.mp3` files.
- 🎛️ **8-Slot Music Sequencer** – Each slot maps to one step in the music timeline.

---

## 🧰 Folder Structure

```
rhythmbeats/
├── index.html               # Main web interface
├── model/                   # Teachable Machine model folder
│   ├── model.json
│   ├── metadata.json
│   └── weights.bin
├── sounds/                  # Audio clips by instrument/note
│   ├── piano/
│   │   ├── A.mp3
│   │   ├── B.mp3
│   │   └── ...
│   └── guitar/
│       ├── C.mp3
│       ├── D.mp3
│       └── ...
└── arduino/
    └── rhythmbeats.ino      # Arduino sketch for slot detection
```

---

## 🛠 Requirements

### Browser
- ✅ Google Chrome (supports Web Serial API)
- ✅ Webcam access permission

### Hardware
- 🟦 Arduino UNO (or compatible)
- 🔘 8 push buttons (one per slot)
- 💡 8 LEDs (one per slot for visual feedback)
- 🧱 Labeled cubes (e.g. "Piano A", "Guitar C")

### Software
- 🧠 [Teachable Machine](https://teachablemachine.withgoogle.com/) – Export your image model and save under `model/`
- 🎧 `.mp3` sound files named like `sounds/piano/C.mp3`

---

## 🧪 Setup

### 1. Clone the Repo
```bash
git clone https://github.com/yourusername/rhythmbeats.git
cd rhythmbeats
```

### 2. Start a Local Web Server
(Required for webcam + Web Serial to work)

Using Python:
```bash
python3 -m http.server
```

Or use [Live Server](https://marketplace.visualstudio.com/items?itemName=ritwickdey.LiveServer) in VS Code.

### 3. Upload Arduino Code
Open `arduino/rhythmbeats.ino` in the Arduino IDE and upload to your board.

### 4. Open in Browser
Visit `http://localhost:8000` in Chrome, click **“Connect Arduino”**, then **“Play Sequence”** after placing cubes.

---

## 🎼 How It Works

1. **Teachable Machine** classifies the cube’s instrument and note.
2. **Arduino** detects which slot was activated (button pressed).
3. The browser maps that slot to the **last classified cube type**.
4. On "Play", the browser plays the sequence of sounds.

---

## 📦 Model Guidelines

Make sure your Teachable Machine image model includes:
- Distinct backgrounds and lighting
- Labels like: `BlueCubeWithA : Piano A`, `RedCubeWithG : Guitar G`
- A fallback class like `None` or `Empty` to detect empty canvas

---

## 🎉 Demo Video

📺 *Coming soon…*

---

## 📄 License

MIT License – use, remix, and build on RhythmBeats freely.

---

## 💬 Credits

Built by Chaiitanyaa & Aimee
Project inspired by tangible user interfaces and creative music tech!
