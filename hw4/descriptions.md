# Q1) Deteriorating conditions
Gradescope link

 Description
You brought m pieces of armor with you in your quest to explore the towers. The designers of the game want to encourage you to rotate your armor (and try all the latest fashions!) so they created a system where your armor wears out faster if you use it in multiple fights per day.

Each fight has a baseline number of strength points that it will cause your armor to lose if you wear it while fighting. In the first battle you wear it for, it only loses that many points.  The second time, you lose twice that many points, the third time is triple and so on, such that the kth time is k-times the base cost.

Given m pieces of armor and n fights, and a base cost of Ci for fight i, find and print the minimum total amount of strength points your armor will lose collectively.

Note: You can choose what order the fights happen in.

Input Format

The first line contains two space-separated integers describing the respective values of n and m.
The second line contains n space-separated positive integers describing the respective values of C0, C1, …, Cn-1
Constraints

1 ≤ n, m ≤ 100
1 ≤ Ci ≤ 106
answer < 231
0 ≤ i < n
Output Format

Print the total cost for all fights.

# Q2) Monstrous Power
Gradescope link

Description
On your way home from questing, Sierra asks for more help. Ever since you helped her edit her source code, Sierra has been looking for ways to further increase her virtual power. The more power she has, the more she can help you go on virtual adventures, so you’re not complaining (although the incident with the robots is starting to make you uneasy). However, she is worried about tipping off the CloudLattice developers by using too much computation. Fortunately, she has found a workaround: by exploiting the simple path-finding rules that govern monsters in the game, she is able to build logic gates out of the monsters that spawn in the wilderness areas of the game and use them for computation (it’s not particularly efficient, but she’s kind of desperate).

The wilderness areas in the game are arranged in a line. To avoid raising suspicion, Sierra wants to avoid using any wilderness areas that are adjacent to each other. The more monsters an area has, the more computation it can do for her.

Help Sierra choose a set of wilderness areas to co-opt such that you maximize the computational power she can get while avoiding selecting any adjacent sections of wilderness.

Given a series of N wilderness areas where area i, in order, has Mi monsters, determine the maximum total number of monsters (and therefore amount of computation) that can be obtained.

Input Format

The first line provides N, the number of wilderness areas in the row.
The second line has N values, separated by spaces, indicating the number of monsters in each area (M0 through MN-1 ).
Constraints

1 ≤ N ≤ 106
1 ≤ Mi ≤ 1010
Output Format

A single number indicating the maximum total number of monsters possible.

# Q3) Maximizing Monsters
Gradescope link

Description
In her experiments with building an in-game analog computer out of monsters, Sierra has learned something else. She can increase her computational power by luring monsters to the wilderness areas she has control of, but trying to put too many monsters in the same area leads to weird glitches.

Sierra has identified many different logic gates that she can build out of monsters. Each one takes a different number of monsters. She wants to pack as many logic gates into each wilderness area as she can without things starting to get glitchy.

There are N types of logic gates that Sierra can make out of monsters.  Each gate i uses Mi monsters, with K being the maximum total monsters that can be in an area without glitches.  Determine that maximum number of monsters that can productively be in that area at once (i.e. if every monster has to be part of a logic gate, what is the most monsters that can be in the area with triggering glitches).

For example, if there were two types of logic gate that needed 9 and 12 monsters respectively, and the area could handle a maximum of 31 monsters, in practice, Sierra could have a maximum of 30 monsters doing computation by arranging them into two of the first logic gate type and one of the second logic gate type. If there were a type of logic gate that only needed 1 monster, she would be able to maximize the amount of computation to a total of 31 monsters, but no such logic gate exists so no existing combination of gates can get her all the way to 31.

Input Format

The first line contains T, the number of test cases.
Each test comprises two lines:
The first line contains two integers, N and K, representing the number of logic gate types and maximum monsters that can be used in total, respectively.
The second line consists of space separated integers, M0 through MN-1, representing the number of monsters each logic gate type requires.
Constraints

1 ≤ T ≤ 10
1 ≤ N, K ≤ 2000
1 ≤ Mi ≤ 2000
Output Format

Output T lines, the maximum total monsters that can be used in each test case without exceeding the total limit ( K ).

# Q4) The weirdest programming language
Note: There seems to be a big time efficiency difference between Python and C++ for this problem; C++ is recommended if you don’t want to wait.
Gradescope link

Description
Now that she’s got her monsters organized, Sierra wants to know how versatile the computations she can do with them are. She wants to know how many different sequences of logic gates she can make out of N monsters.

Given G types of logic gates, where gate type i uses Ni monsters, how many ways are there to make a sequence of logic gates made up of exactly Ntotal monsters?  Note that order DOES matter.

Input Format

The first line of the input provides T, the total number of test cases.
The next T pairs of lines describe a single test case:
The first line in a test case provides the number of gate types (G) and the total target number of monsters ( Ntotal ).
The second line has G values, each position indicating the number of monsters (Ni) needed to make logic gate type i.
Constraints

1 ≤ T ≤ 10
1 ≤ G ≤ 50
1 ≤ Ntotal ≤ 106
1 ≤ Ni ≤ 106
Output Format

T lines, one per test case, each indicating the number of combinations possible to make a sequence with that total number of monsters. Some of the values are quite large, so mod your answer by 1000000009. Note: make sure you read that last sentence!