# Task Tracker (Qt)

Un **Task Tracker simplu** realizat în C++ folosind Qt, pentru gestionarea task-urilor cu:
✅ Adăugare task  
✅ Ștergere task  
✅ Marcare ca finalizat  
✅ Export / Import XML  
✅ Salvarea temei și a ultimei căi de fișier  
✅ Schimbare temă light/dark  
✅ Ștergere toate task-urile cu confirmare

---

## 🛠 Cerințe proiect:
1. Gestionarea task-urilor cu titlu, descriere, dată, status.
2. Salvarea și încărcarea task-urilor folosind XML.
3. Interfață cu `QTableWidget` pentru vizualizare.
4. Opțiune de schimbare temă (light/dark).
5. Salvarea temei și ultimei căi utilizate folosind `QSettings`.
6. Funcție de ștergere a tuturor task-urilor cu confirmare (`QMessageBox`).
7. Persistența datelor între rulări.

---

## ⚡ Cum rulezi proiectul

1. Clonare repository:
    ```bash
    git clone https://github.com/user/TaskTracker.git
    cd TaskTracker
    ```

2. Deschide proiectul în **Qt Creator**:
    - File > Open File or Project > `TaskTracker.pro`

3. Rulează proiectul cu butonul **Run (verde)**.

---

## 🧩 Tehnologii utilizate
- **C++**
- **Qt (Widgets, XML, QSettings, QMessageBox, QTableWidget)**

---

## 📂 Structură proiect
- `main.cpp` – pornirea aplicației.
- `mainwindow.cpp/.h` – logica aplicației.
- `mainwindow.ui` – interfața grafică.
- `TaskTracker.pro` – fișierul de proiect Qt.
- `README.md` – descrierea proiectului.

---

## 🙌 Autor
Proiect realizat pentru laboratorul de **Programare orientată pe obiect C++ / Tehnologii de programare vizuală**.

---

## 📌 Notă
- Poți adapta codul pentru a adăuga **filtrare, sortare** sau **persistență avansată cu SQLite** pentru funcționalități suplimentare.