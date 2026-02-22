<h1 align="center">🚗 Gesture Controlled Car using ESP32 & Accelerometer</h1>

<p align="center">
Control a robotic car using hand gestures powered by an accelerometer and ESP-NOW wireless communication.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Platform-ESP32-blue">
  <img src="https://img.shields.io/badge/Communication-ESP--NOW-green">
  <img src="https://img.shields.io/badge/Type-Robotics-orange">
  <img src="https://img.shields.io/badge/Made%20By-Manan%20Kush-red">
</p>

---

<h2>📌 Project Overview</h2>

<p>
This project implements a <b>gesture-controlled robotic car</b> where the vehicle moves based on hand movements.
An <b>ADXL345 accelerometer</b> mounted on a wearable controller detects gestures and sends motion data wirelessly
to another ESP32 mounted on the car.
</p>

<ul>
<li>Forward Movement</li>
<li>Backward Movement</li>
<li>Left Turn</li>
<li>Right Turn</li>
<li>Stop</li>
</ul>

---

<h2>⚙️ Working Principle</h2>

<h3>🧤 Transmitter (Hand Controller)</h3>
<ul>
<li>ADXL345 detects hand tilt</li>
<li>ESP32 reads accelerometer data via I2C</li>
<li>Data transmitted wirelessly using ESP-NOW</li>
</ul>

<h3>🚙 Receiver (Car)</h3>
<ul>
<li>ESP32 receives gesture data</li>
<li>Direction calculated using axis values</li>
<li>Motor driver controls DC motors</li>
</ul>

---

<h2>🧠 System Architecture</h2>

<p align="center">
Hand Gesture → Accelerometer → ESP32 Sender → ESP-NOW → ESP32 Receiver → Motor Driver → Car Movement
</p>

---

<h2>🧰 Hardware Components</h2>

<h3>Controller Side</h3>
<ul>
<li>ESP32</li>
<li>ADXL345 Accelerometer</li>
<li>Battery Pack</li>
</ul>

<h3>Car Side</h3>
<ul>
<li>ESP32</li>
<li>Motor Driver (L298N or similar)</li>
<li>DC Motors</li>
<li>Robot Chassis</li>
<li>Battery Pack</li>
</ul>

---

<h2>🔌 Pin Configuration (Receiver ESP32)</h2>

<table>
<tr>
<th>Function</th>
<th>GPIO</th>
</tr>
<tr>
<td>Right Forward</td>
<td>26</td>
</tr>
<tr>
<td>Right Backward</td>
<td>19</td>
</tr>
<tr>
<td>Left Forward</td>
<td>27</td>
</tr>
<tr>
<td>Left Backward</td>
<td>17</td>
</tr>
<tr>
<td>PWM Motor Speed 1</td>
<td>32</td>
</tr>
<tr>
<td>PWM Motor Speed 2</td>
<td>33</td>
</tr>
</table>

---

<h2>📡 Communication</h2>

<ul>
<li>Protocol: <b>ESP-NOW</b></li>
<li>Mode: WiFi Station Mode</li>
<li>Peer-to-peer wireless communication</li>
<li>Low latency control</li>
</ul>

---

<h2>🧑‍💻 Software Used</h2>

<ul>
<li>Arduino IDE</li>
<li>ESP32 Board Package</li>
<li>Wire Library</li>
<li>ESP-NOW Library</li>
</ul>

---

<h2>📁 Project Structure</h2>

<pre>
Gesture-Controlled-Car/
│
├── Gesture Controlled Car.ino
├── Gesture Controlled Car Receive.ino
└── README.md
</pre>

---

<h2>🚀 Installation & Setup</h2>

<h3>1️⃣ Install ESP32 Support</h3>

<pre>
https://dl.espressif.com/dl/package_esp32_index.json
</pre>

<ul>
<li>Open Arduino IDE</li>
<li>Go to Preferences</li>
<li>Add Board URL</li>
<li>Install ESP32 from Board Manager</li>
</ul>

<h3>2️⃣ Upload Transmitter Code</h3>
<ul>
<li>Connect controller ESP32</li>
<li>Open <b>Gesture Controlled Car.ino</b></li>
<li>Upload code</li>
</ul>

<h3>3️⃣ Upload Receiver Code</h3>
<ul>
<li>Connect car ESP32</li>
<li>Open <b>Gesture Controlled Car Receive.ino</b></li>
<li>Upload code</li>
</ul>

<h3>4️⃣ Update MAC Address</h3>

<pre>
uint8_t broadcasting_add[] = {XX, XX, XX, XX, XX, XX};
</pre>

Replace with receiver ESP32 MAC address.

---

<h2>🎮 Gesture Controls</h2>

<table>
<tr>
<th>Gesture</th>
<th>Action</th>
</tr>
<tr>
<td>Tilt Forward</td>
<td>Move Forward</td>
</tr>
<tr>
<td>Tilt Backward</td>
<td>Move Backward</td>
</tr>
<tr>
<td>Tilt Left</td>
<td>Turn Left</td>
</tr>
<tr>
<td>Tilt Right</td>
<td>Turn Right</td>
</tr>
<tr>
<td>Neutral Position</td>
<td>Stop</td>
</tr>
</table>

---

<h2>✨ Features</h2>

<ul>
<li>Wireless control without router</li>
<li>Low latency ESP-NOW communication</li>
<li>PWM motor speed control</li>
<li>Wearable gesture controller</li>
<li>Real-time motion response</li>
</ul>

---

<h2>🔮 Future Improvements</h2>

<ul>
<li>Obstacle avoidance</li>
<li>Camera streaming</li>
<li>AI gesture recognition</li>
<li>Mobile app control</li>
<li>Autonomous navigation</li>
</ul>

---

<h2>⭐ Support</h2>

<p>If you like this project, please give it a ⭐ on GitHub!</p>
