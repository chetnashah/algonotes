
## description

Minimizing lateness problem.
* Single resource processes one job at a time.
* Job `j` requires `t[j]` units of processing time and is due at time `d[j]`.
* If `j` starts at time `s[j]`, it finishes at time `f[j] = s[j] + t[j]`.
* Lateness: `lj = max { 0, f[j] - d[j] }`.
**Goal: schedule all jobs to minimize maximum lateness L = max l[j].**

## 