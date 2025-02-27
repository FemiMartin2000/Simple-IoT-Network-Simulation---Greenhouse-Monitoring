

# 🌱 Simple IoT Network Simulation – Greenhouse Monitoring 🌿

This project simulates a simple **IoT-based greenhouse monitoring system** using **OMNeT++**. The system models a **wireless sensor network**, a **gateway**, and a **user interface (farmer’s computer)** to analyze **performance, energy efficiency, and data transmission delay**.

## 🏗 Project Overview

The simulation is divided into **two parts**:

### 🔹 Part 1: Basic Greenhouse Sensor Network
- **Five sensors** monitor:
  - **Air humidity**
  - **Temperature**
  - **Soil moisture**
- Sensors communicate **wirelessly** with a **gateway**.
- The **gateway** transmits data to the **farmer’s computer**.
- **Goal**: Measure the system’s **runtime** before sensors run out of battery.

### 🔹 Part 2: Extended System with More Features
- **New sensors** with **higher accuracy** but **higher energy consumption**.
- **Additional gateway** and a **router** for improved scalability.
- **Wireless delay modeling** to simulate real-world conditions.
- **Goals**:
  - Optimize **sensor wake-up cycles** for a **4-week battery life**.
  - Determine **ideal battery capacity** for efficient operation.
  - Analyze **transmission delays** for better system performance.

---

## 🚀 How to Run the Simulation

### 🛠 Requirements
- **OMNeT++ (v5.6+)**
- **Python**
- **matplotlib** (for result visualization)

### 📥 Setup & Execution
1. **Clone the repository**
2. **Open OMNeT++** and load the project.
3. **Run the simulation** inside OMNeT++.
4. **Analyze the results** (energy trends, delays, and sensor lifespan).

---

## 📊 Analysis & Expected Results
- **Energy Consumption Trends**: How long do sensors last before battery depletion?
- **Transmission Delays**: Impact of network topology on real-time data collection.
- **Battery Optimization**: Best configurations for extended sensor operation.

---
