<h2><a href="https://www.geeksforgeeks.org/problems/reverse-alternate-levels-of-a-perfect-binary-tree/1">Reverse alternate levels of a perfect binary tree</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a complete binary tree, reverse the nodes present at alternate levels.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>root = [1, 3, 2]
             1
           /   \
          3     2</span>
<strong><span style="font-size: 18px;">Output:</span></strong>
<span style="font-size: 18px;">             1
           /   \
          2     3</span>

<span style="font-size: 18px;"><strong>Explanation: </strong>Nodes at level 2 are reversed.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> root = [1, 2, 3, 42, 51, 63, 72
              1
           /     \
         2        3
       /  \      /     \
     42   51   63   72</span>
<span style="font-size: 18px;"><strong>Output:</strong>
              1
           /     \
         3        2
       /  \      /     \
     42   51   63   72</span>

<span style="font-size: 18px;"><strong>Explanation: </strong>Nodes at level 2 are reversed. Level 1 and 3 remain as it is.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>root = [1, 3, 4]
             1
           /   \
          3     4</span>
<strong><span style="font-size: 18px;">Output:</span></strong>
<span style="font-size: 18px;">             1
           /   \
          4     3</span>

<span style="font-size: 18px;"><strong>Explanation: </strong>Nodes at level 2 are reversed.</span></pre>
<p><span style="font-size: 18px;"><strong>Note:</strong> If you click on Compile and Test the output will be the in-order traversal of the modified tree.</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ number of nodes ≤ 10<sup>5</sup><br>1 ≤ nodes-&gt;data ≤ 10<sup>5</sup><br></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Hike</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;