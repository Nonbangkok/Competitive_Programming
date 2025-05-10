## 📌 README.md

# 📘 โจทย์: ลำดับฟีโบนัชชีด้วย Dynamic Programming

## 🧠 คำอธิบาย

ให้นักเรียนเขียนฟังก์ชัน `int fibonacci(int n);` เพื่อหาค่าลำดับ Fibonacci ลำดับที่ $n$ โดยใช้แนวคิด **Dynamic Programming**

## 📥 อินพุต

* จำนวนเต็ม $n$ โดยที่ $0 \leq n \leq 30$

## 📤 เอาต์พุต

* แสดงค่า Fibonacci ลำดับที่ $n$

## 🔒 ข้อกำหนด

* ห้ามใช้ recursion แบบปกติ เช่น `return fibonacci(n-1) + fibonacci(n-2);`
* ต้องใช้การจดจำคำตอบเดิม (Memoization หรือ Bottom-Up DP)
* ให้ใช้แค่ `vector` จาก Standard Library เท่านั้น

## 🧪 ตัวอย่าง

| Input | Output |
| ----- | ------ |
| 0     | 0      |
| 1     | 1      |
| 4     | 3      |
| 7     | 13     |
| 10    | 55     |

## 🎯 เป้าหมายการเรียนรู้

* เข้าใจพื้นฐานของ Dynamic Programming
* เขียนโค้ดที่ใช้การจำคำตอบเก่าเพื่อลดเวลาทำงาน
* ฝึกวิเคราะห์และออกแบบอัลกอริทึมอย่างเป็นระบบ

## ▶️ วิธี execute

* เข้าไปที่ `fibonacci`
* ```make run build```