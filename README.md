# deadlock-prevention-toolkit
OS Project: Deadlock Prevention and Recovery Toolkit using C++

This project is a simple but complete toolkit that demonstrates how operating systems handle **deadlocks**.  
It includes:

- Deadlock **prevention**
- Deadlock **detection**
- Deadlock **recovery**
- A working implementation of **Banker’s Algorithm**
- A basic **Resource Allocation Graph (RAG)** based deadlock check
- A small menu-driven simulation program in C++

The goal of this project is to help understand how resource allocation works inside an OS and how the system avoids unsafe situations.
---
## 📌 What This Project Can Do

✔ Check if the system is in a safe state  
✔ Compute the Need matrix  
✔ Allow users to request additional resources  
✔ Approve or reject resource requests based on Banker's Algorithm  
✔ Detect deadlocks using a cycle-checking technique  
✔ Recover from deadlocks by terminating a process  
✔ Simulate multiple scenarios interactively  

---

## 📁 Project Structure

```
deadlock-prevention-toolkit/
│
├── src/
│   └── deadlock.cpp        # Main source file
│
├── docs/
│   ├── Report.md           # Full project report
│   ├── Flowchart.png       # Flowchart for the algorithm
│   └── Viva_Questions.md   # Viva preparation questions
│
└── README.md
```

---

## 🔧 How to Compile and Run

Open your terminal and type:

### **Compile**
```bash
g++ src/deadlock.cpp -o deadlock
```

### **Run**
```bash
./deadlock
```

---

## 🧪 Input Format (Simple Example)

The program will ask for:

1. Number of processes  
2. Number of resources  
3. MAX matrix  
4. ALLOCATION matrix  
5. AVAILABLE vector  

Example input:

```
3 3
7 5 3
3 2 2
9 0 2
0 1 0
2 0 0
3 0 2
3 3 2
```

---

## 🎮 Program Menu

When you run the program, you will see:

```
1. Check Safe State
2. Request Resources
3. Detect Deadlock
4. Exit
```

You can repeatedly choose different options to test scenarios.

---

## 💡 Algorithms Used

### **1. Banker’s Algorithm**
Used for:
- Checking safe states  
- Verifying if a resource request is safe  

### **2. Resource Allocation Graph (RAG)**
Used for:
- Detecting cycles  
- Finding if any process is part of a deadlock  

### **3. Deadlock Recovery**
When a deadlock is detected:
- The program forces a recovery by terminating a selected process  
- Freed resources are returned to the system

---

## 📄 Documentation

The complete project report is available in:

```
docs/Report.md
```

It includes diagrams, explanation, advantages, limitations, and module details.


## 👩‍💻 Author

**Vani Bhardwaj**  
Roll No: RK24PRA11  
**Riya**
Roll No: RK24PRA10
B.Tech CSE – Operating Systems Project  
---

## ⭐ If This Helped You
Give a star ⭐ to this repository — it motivates future updates!

