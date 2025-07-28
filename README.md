# 🌀 push_swap

> A sorting algorithm project from [42 School](https://42.fr), focused on constrained operations and algorithmic efficiency.

---

## 🧠 Objective

The goal is to sort a list of integers using two stacks (`a` and `b`) with a very limited set of operations:

- `sa`, `sb`, `ss` — swap the top two elements
- `pa`, `pb` — push the top element from one stack to the other
- `ra`, `rb`, `rr` — rotate stack (top becomes bottom)
- `rra`, `rrb`, `rrr` — reverse rotate stack

The final output must be the most optimal sequence of instructions to sort the input list, minimizing the total number of operations.

---

## 🗃️ Project Structure

```bash
push_swap/
├── src/             # Core logic (parsing, sorting, operations)
├── includes/        # Header files
├── libft/           # Custom C library
├── Makefile         # Build system
├── push_swap.c      # Entry point
└── README.md
