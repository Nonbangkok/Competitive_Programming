# 📘 โจทย์: Inversion Count ด้วย Merge Sort

## 🧠 คำอธิบาย

ให้นักเรียนเขียนโปรแกรมเพื่อนับจำนวน inversion ในอาเรย์ โดยนิยามว่า inversion คือคู่ของดัชนี (i, j) ที่ `i < j` และ `arr[i] > arr[j]` โดยใช้เทคนิค Merge Sort เพื่อให้ทำงานได้ในเวลา $O(N \log N)$

## 📥 อินพุต

* อาเรย์ของจำนวนเต็มไม่ซ้ำกัน ความยาว $N$

## 📤 เอาต์พุต

* จำนวน inversion ทั้งหมดในอาเรย์

## 🔒 ข้อกำหนด

* ต้องใช้เทคนิค Merge Sort ในการนับเท่านั้น
* ห้ามใช้การวนลูปเช็คทุกคู่แบบ brute-force

## 🧪 ตัวอย่าง

| Input           | Output |
| --------------- | ------ |
| {1, 2, 3, 4, 5} | 0      |
| {5, 4, 3, 2, 1} | 10     |
| {1, 3, 2, 3, 1} | 4      |

## 🎯 เป้าหมายการเรียนรู้

* เข้าใจนิยามของ inversion
* ประยุกต์ใช้ Merge Sort กับการนับข้อมูลในช่วง
* พัฒนาอัลกอริทึมที่มีประสิทธิภาพ

## ▶️ วิธี execute

* เข้าไปที่ directory `inversion_count`
* รันคำสั่ง:

  ```bash
  make run build
  ```
