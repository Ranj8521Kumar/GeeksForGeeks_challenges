<h2><a href="https://www.geeksforgeeks.org/problems/toggle-bits-given-range0952/1">Toggle bits in the given range</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a non-negative number <strong>n</strong> and two values <strong>l</strong> and <strong>r</strong>. The problem is to toggle the bits in the range l to r in the binary representation of n, i.e., to toggle bits from the <strong>lth</strong> least significant bit to the <strong>rth</strong> least significant bit (the rightmost bit as counted as the <strong>first </strong>bit).<br></span></p>
<blockquote>
<p><span style="font-size: 18px;">A toggle operation <strong>flips</strong> a bit <strong>0</strong> to <strong>1</strong> and a bit <strong>1</strong> to <strong>0</strong>.</span></p>
</blockquote>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;"><strong>n</strong> = 17 , <strong>l</strong> = 2 , <strong>r</strong> = 3</span>
<span style="font-size: 18px;"><strong>Output:</strong></span>
<span style="font-size: 18px;">23</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">(17)<sub>10</sub> = (10001)<sub>2</sub>.  After toggling all
the bits from 2nd to 3rd position we get
(10111)<sub>2</sub> = (23)<sub>10</sub></span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<span style="font-size: 18px;"><strong>n</strong> = 50 , <strong>l</strong> = 2 , <strong>r</strong> = 5</span>
<span style="font-size: 18px;"><strong>Output:</strong></span>
<span style="font-size: 18px;">44</span>
<span style="font-size: 18px;"><strong>Explanation:</strong></span>
<span style="font-size: 18px;">(50)<sub>10</sub> = (110010)<sub>2</sub>.  After toggling all
the bits from 2nd to 5th position we get
(101100)<sub>2</sub> = (44)<sub>10</sub></span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>toggleBits()</strong> which takes <strong>three </strong>Integers n, l and r as input and returns the modified <strong>Integer </strong>as the answer.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(1)<br><strong>Expected Auxiliary Space:</strong> O(1)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong></span><br><span style="font-size: 18px;">1 &lt;= n &lt;= 10<sup>5</sup><br>1 &lt;= l&lt;=r &lt;=<sup> </sup>Number of Bits in n</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Bit Magic</code>&nbsp;<code>Data Structures</code>&nbsp;