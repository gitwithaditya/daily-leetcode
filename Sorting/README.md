<div align="center">

# 📚 Sorting

### *The foundation of efficient problem solving.*

> **"Sorting is not just about arranging data — it's about unlocking faster and smarter algorithms."**

</div>

---

# 📖 What is Sorting?

Sorting is the process of arranging data in a specific order, usually in **ascending** or **descending** order.

It is one of the most fundamental concepts in Data Structures & Algorithms and serves as the backbone of many advanced algorithms.

### Example

Before Sorting

```text
9 4 7 2 8 1
```

After Sorting (Ascending)

```text
1 2 4 7 8 9
```

---

# ❓ Why is Sorting Important?

Sorting helps in:

- ⚡ Faster searching (Binary Search requires sorted data)
- 📊 Efficient data organization
- 🔍 Easier duplicate detection
- 🤝 Simplifying complex algorithms
- 🚀 Optimizing overall program performance

Many interview problems become much easier after sorting the input.

---

# 📚 Sorting Algorithms Covered

| Algorithm | Status |
|:---------|:------:|
| Bubble Sort | ⏳ |
| Selection Sort | ⏳ |
| Insertion Sort | ⏳ |
| Merge Sort | ⏳ |
| Quick Sort | ⏳ |

> ⏳ = Yet to be documented

---

# ⏱️ Time Complexity Comparison

| Algorithm | Best | Average | Worst | Stable | In-place |
|-----------|------|---------|-------|:------:|:--------:|
| Bubble Sort | O(n) | O(n²) | O(n²) | ✅ | ✅ |
| Selection Sort | O(n²) | O(n²) | O(n²) | ❌ | ✅ |
| Insertion Sort | O(n) | O(n²) | O(n²) | ✅ | ✅ |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | ✅ | ❌ |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | ❌ | ✅ |

---

# 🧠 Stable vs Unstable Sorting

### ✅ Stable Sorting

A sorting algorithm is **stable** if it preserves the relative order of equal elements.

Examples:

- Bubble Sort
- Insertion Sort
- Merge Sort

---

### ❌ Unstable Sorting

The relative order of equal elements may change.

Examples:

- Selection Sort
- Quick Sort

---

# 💾 In-place vs Out-of-place Sorting

### ✅ In-place Sorting

Uses very little extra memory.

Examples:

- Bubble Sort
- Selection Sort
- Insertion Sort
- Quick Sort

---

### ❌ Out-of-place Sorting

Requires additional memory.

Example:

- Merge Sort

---

# ⚖️ Comparison vs Non-Comparison Sorting

### Comparison-Based

Elements are compared with each other.

Examples:

- Bubble Sort
- Selection Sort
- Merge Sort
- Quick Sort

Time Complexity Lower Bound:

```text
O(n log n)
```

---

### Non-Comparison Based

Sorting is done without comparing elements directly.

Examples:

- Counting Sort
- Radix Sort
- Bucket Sort

These algorithms can achieve linear time under certain conditions.

---

# 🎯 When Should You Use Which Algorithm?

| Algorithm | Best Use Case |
|-----------|---------------|
| Bubble Sort | Learning & understanding sorting concepts |
| Selection Sort | When memory writes should be minimized |
| Insertion Sort | Small or nearly sorted arrays |
| Merge Sort | Stable sorting and linked lists |
| Quick Sort | General-purpose fast sorting |

---

# 💡 Interview Tips

- Learn the intuition behind each algorithm instead of memorizing it.
- Be comfortable explaining the time and space complexity.
- Know whether the algorithm is stable or unstable.
- Understand when one sorting algorithm is preferred over another.
- Practice writing each sorting algorithm from scratch.

---

# 📂 Repository Structure

```text
Sorting
│
├── README.md
├── Bubble_Sort
├── Selection_Sort
├── Insertion_Sort
├── Merge_Sort
└── Quick_Sort
```

---

# 📌 Problems Covered

- ⏳ Bubble Sort
- ⏳ Selection Sort
- ⏳ Insertion Sort
- ⏳ Merge Sort
- ⏳ Quick Sort

> This section will be updated as I continue documenting each algorithm.

---

<div align="center">

## 🚀 Keep Learning, Keep Improving.

**Adapt. Learn. Build. Repeat.**

</div>
