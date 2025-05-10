# Binary Search

ให้นักเรียนเขียนฟังก์ชัน `binary_search` ที่ทำการค้นหาเลขใน array หรือ vector ที่เรียงลำดับแล้ว (ascending order)

## เงื่อนไข
- ถ้าพบ target ใน list ให้ return index ที่พบ
- ถ้าไม่พบ ให้ return -1

## ข้อจำกัด
- ห้ามใช้ฟังก์ชัน library สำหรับค้นหา (เช่น std::find หรือ bsearch)
- ให้ใช้ binary search เท่านั้น

## ตัวอย่าง

```cpp
binary_search({1, 2, 3, 4, 5}, 3) -> 2
binary_search({1, 2, 3, 4, 5}, 6) -> -1
```

## ▶️ วิธี execute

* เข้าไปที่ `binary_search`
* ```make run build```
