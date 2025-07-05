In the village of Algolab 🏡, a group of villagers $P$ start on the left side ⬅️ of a cursed bridge, needing to cross to the right ➡️ before darkness consumes them 🌑. They have only one magical torch 🔥✨, and the bridge allows at most two people at a time 🚶‍♂️🚶‍♀️. Each villager moves at their own fastest pace, but they can slow down at will, and when two cross together, they must move together as the magical torch illuminates little ⏳🐢. After each crossing, someone must return with the torch for the others.

Given any $n$ villagers with respective speeds $P_i$, devise an algorithm to determine the minimum total time $t$ required for all to cross safely ✅.

Can you help Algolab escape the night’s curse? 🌙🕰️

---

**Input Format**
> First line is an integer $n$, the number of people,
>
> Following $n$ integers represent $P_i$, the maximum pace of each person.

**Output Format**
> An integer $t$, minimum required time for all to pass safely.

**Constraints**
> $1 \le n \le 10^6$
>
> $1 \le P \le 10^9$