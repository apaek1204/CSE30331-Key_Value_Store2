Project 04 - Key-Value Store II
===============================

This [project] implements a variety of [map] backends for a basic [key-value
store].

[project]:          https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/project04.html
[map]:              https://en.wikipedia.org/wiki/Associative_array
[key-value store]:  https://en.wikipedia.org/wiki/Key-value_database


Questions:

1. | Backend | avg insert | worst insert | avg search | worst search |
|---|---|---|---|---|
| unordered | O(1) | O(n) | O(1) | O(n) |
|chained | O(1) | O(n) | O(1) | O(n) |
| open | O(1) | O(n) | O(1) | O(n) |

    All the average complexities are O(1) because since we expect there to be very few collisions, making searching constant. Since insert is based off of searching (in case the key already exists), we expect a constant insert time.
    The worst case is all O(n) because in the worst case, all keys hash to the same bucket. In the case of unordered and chained, this will turn into linked lists, while for open, it'll have to consistently search through the buckets until it finds the correct one. Again, since insert is based off of searching, we expect them to have the same complexity.

2. | Backend | NITEMS | INSERT | SEARCH |
|---|---|---|---|
| unsorted | 10 | 4.4632e-05 | 1.2297e-05 |
| sorted | 10 | 4.8504e-05 | 1.1552e-05 |
| bst | 10 | 4.2288e-05 | 1.2574e-05 |
| rbtree | 10 | 5.0195e-05 | 1.3352e-05 |
| treap | 10 | 8.2963e-05 | 8.397e-06 |
| unordered | 10 | 4.5161e-05 | 1.421e-05 |
| chained-0.5 | 10 | 4.309e-05 | 1.6366e-05 |
| chained-0.75 | 10 | 4.2608e-05 | 1.6609e-05 |
| chained-1.0 | 10 | 4.9273e-05 | 1.7049e-05 |
| chained-5.0 | 10 | 4.6211e-05 | 1.6217e-05 |
| chained-10.0 | 10 | 4.3953e-05 | 1.5826e-05 |
| chained-100.0 | 10 | 4.9409e-05 | 2.0168e-05 |
| open-0.5 | 10 | 3.8012e-05 | 1.224e-05 |
| open-0.6 | 10 | 3.9506e-05 | 1.2279e-05 |
| open-0.7 | 10 | 4.1173e-05 | 1.1432e-05 |
| open-0.8 | 10 | 4.4477e-05 | 1.2809e-05 |
| open-0.9 | 10 | 4.0247e-05 | 1.1257e-05 |
| open-1.0 | 10 | 4.0173e-05 | 1.1887e-05 |
| unsorted | 100 | 0.00047983 | 0.00044037 |
| sorted | 100 | 0.00059501 | 0.00011207 |
| bst | 100 | 0.00013457 | 9.5915e-05 |
| rbtree | 100 | 0.00018021 | 0.00010439 |
| treap | 100 | 0.0001757 | 8.3349e-05 |
| unordered | 100 | 0.00019579 | 7.5678e-05 |
| chained-0.5 | 100 | 0.00014418 | 9.7132e-05 |
| chained-0.75 | 100 | 0.00016378 | 9.5874e-05 |
| chained-1.0 | 100 | 0.00013742 | 9.3998e-05 |
| chained-5.0 | 100 | 0.00012503 | 9.1953e-05 |
| chained-10.0 | 100 | 0.00012192 | 9.6128e-05 |
| chained-100.0 | 100 | 0.00012409 | 9.2206e-05 |
| open-0.5 | 100 | 0.00011476 | 6.3909e-05 |
| open-0.6 | 100 | 9.9328e-05 | 6.6576e-05 |
| open-0.7 | 100 | 0.00011409 | 6.8561e-05 |
| open-0.8 | 100 | 0.00010149 | 6.9562e-05 |
| open-0.9 | 100 | 0.00010403 | 6.4576e-05 |
| open-1.0 | 100 | 0.00010363 | 6.343e-05 |
| unsorted | 1000 | 0.039433 | 0.036242 |
| sorted | 1000 | 0.046036 | 0.0015353 |
| bst | 1000 | 0.0013478 | 0.0011896 |
| rbtree | 1000 | 0.001805 | 0.0012025 |
| treap | 1000 | 0.0015295 | 0.0010794 |
| unordered | 1000 | 0.0013887 | 0.00071727 |
| chained-0.5 | 1000 | 0.0030538 | 0.00091106 |
| chained-0.75 | 1000 | 0.0036422 | 0.00092162 |
| chained-1.0 | 1000 | 0.0011285 | 0.0010014 |
| chained-5.0 | 1000 | 0.0010717 | 0.00096166 |
| chained-10.0 | 1000 | 0.0011125 | 0.0009575 |
| chained-100.0 | 1000 | 0.0010661 | 0.00093252 |
| open-0.5 | 1000 | 0.0018821 | 0.0018843 |
| open-0.6 | 1000 | 0.0019003 | 0.0017643 |
| open-0.7 | 1000 | 0.0019055 | 0.0018068 |
| open-0.8 | 1000 | 0.0018502 | 0.0017572 |
| open-0.9 | 1000 | 0.0019104 | 0.0016857 |
| open-1.0 | 1000 | 0.0019134 | 0.0018193 |
| unsorted | 10000 | 3.8096 | 3.2685 |
| sorted | 10000 | 4.2178 | 0.020824 |
| bst | 10000 | 0.014574 | 0.014255 |
| rbtree | 10000 | 0.021326 | 0.013839 |
| unordered | 10000 | 0.014637 | 0.0081182 |
| chained-0.5 | 10000 | 0.048666 | 0.0093507 |
| chained-0.75 | 10000 | 0.033617 | 0.0092039 |
| chained-1.0 | 10000 | 0.039146 | 0.0094142 |
| chained-5.0 | 10000 | 0.025331 | 0.010356 |
| chained-10.0 | 10000 | 0.014636 | 0.012398 |
| chained-100.0 | 10000 | 0.013883 | 0.012013 |
| open-0.5 | 10000 | 0.019758 | 0.0066003 |
| open-0.6 | 10000 | 0.019547 | 0.0061938 |
| open-0.7 | 10000 | 0.020156 | 0.0065156 |
| open-0.8 | 10000 | 0.019474 | 0.0063284 |
| open-0.9 | 10000 | 0.023484 | 0.0066288 |
| open-1.0 | 10000 | 0.053799 | 0.006778 |
| unsorted | 100000 | INFINITY | INFINITY |
| sorted | 100000 | INFINITY | INFINITY |
| bst | 100000 | 0.17325 | 0.16797 |
| rbtree | 100000 | 0.23767 | 0.1641 |
| treap | 10000 | 0.017447 | 0.013966 |
| treap | 100000 | 0.20259 | 0.17236 |
| unordered | 100000 | 0.1575 | 0.087897 |
| chained-0.5 | 100000 | 0.49426 | 0.10853 |
| chained-0.75 | 100000 | 0.6163 | 0.11689 |
| chained-5.0 | 100000 | 0.40479 | 0.11489 |
| chained-10.0 | 100000 | 0.4236 | 0.1327 |
| chained-100.0 | 100000 | 0.22047 | 0.18391 |
| open-0.5 | 100000 | 0.1855 | 0.075046 |
| open-0.6 | 100000 | 0.18601 | 0.070412 |
| open-0.7 | 100000 | 0.19575 | 0.073229 |
| open-0.8 | 100000 | 0.19043 | 0.073976 |
| open-0.9 | 100000 | 0.19428 | 0.076897 |
| open-1.0 | 100000 | 1.5474 | 0.088402 |
| unsorted | 1000000 | INFINITY | INFINITY |
| sorted | 1000000 | INFINITY | INFINITY |
| bst | 1000000 | 2.0833 | 2.0057 |
| rbtree | 1000000 | 2.6939 | 1.8384 |
| treap | 1000000 | 2.2484 | 2.0471 |
| unordered | 1000000 | 1.7406 | 0.98742 |
| chained-0.5 | 1000000 | 4.3037 | 1.0645 |
| chained-0.75 | 1000000 | 5.3709 | 1.1082 |
| chained-1.0 | 1000000 | 3.7464 | 1.098 |
| chained-5.0 | 1000000 | 4.2238 | 1.3146 |
| chained-10.0 | 1000000 | 4.5969 | 1.552 |
| chained-100.0 | 1000000 | 7.014 | 2.4189 |
| open-0.5 | 1000000 | 1.973 | 0.79109 |
| open-0.6 | 1000000 | 1.9666 | 0.80236 |
| open-0.7 | 1000000 | 1.9525 | 0.81046 |
| open-0.8 | 1000000 | 2.0304 | 0.83621 |
| open-0.9 | 1000000 | 1.9936 | 0.8066 |
| open-1.0 | 1000000 | INFINITY | INFINITY |
| unsorted | 10000000 | INFINITY | INFINITY |
| sorted | 10000000 | INFINITY | INFINITY |
| bst | 10000000 | 24.364 | 22.749 |
| rbtree | 10000000 | 29.537 | 19.978 |
| treap | 10000000 | 25.647 | 23.253 |
| unordered | 10000000 | 21.104 | 10.787 |
| chained-0.5 | 10000000 | 68.308 | 11.563 |
| chained-0.75 | 10000000 | 48.919 | 11.984 |
| chained-1.0 | 10000000 | 58.231 | 12.009 |
| chained-5.0 | 10000000 | 40.566 | 14.217 |
| chained-10.0 | 10000000 | 44.434 | 16.99 |
| chained-100.0 | 10000000 | 71.884 | 28.159 |
| open-0.5 | 10000000 | 28.466 | 8.1022 |
| open-0.6 | 10000000 | 28.713 | 8.1644 |
| open-0.7 | 10000000 | 29.063 | 8.3778 |
| open-0.8 | 10000000 | 28.759 | 7.8159 |
| open-0.9 | 10000000 | 29.671 | 8.3682 |
| open-1.0 | 10000000 | INFINITY | INFINITY |


3. | Backend | Text | File Size | Elapsed Time | Memory |
|---|---|---|---|---|
| unsorted | beowulf.txt | 295K | 15.890 seconds | 2.578 Mbytes
| unsorted | pride.txt | 710K | 27.568 seconds | 2.804 Mbytes
| unsorted | war.txt | 3.2M | 320.800 seconds | 6.105 Mbytes
| sorted | beowulf.txt | 295K | 15.375 seconds | 2.578 Mbytes
| sorted | pride.txt | 710K | 48.265 seconds | 2.801 Mbytes
| sorted | war.txt | 3.2M | 798.052673 seconds | 6.105469 Mbytes
| bst | beowulf.txt | 295K | 0.166973 seconds | 2.953125 Mbytes
| bst | pride.txt | 710K | 0.381941 seconds | 3.222656 Mbytes
| bst | war.txt | 3.2M | 1.728 seconds | 7.395 Mbytes
| rbtree | beowulf.txt | 295K | 0.187970 seconds | 3.144531 Mbytes
| rbtree | pride.txt | 710K | 0.433933 seconds | 3.441406 Mbytes
| rbtree | war.txt | 3.2M | 2.131 seconds | 8.047 Mbytes
| treap | beowulf.txt | 295K | 0.176972 seconds | 2.976562 Mbytes
| treap | pride.txt | 710K | 0.421935 seconds | 3.242188 Mbytes
| treap | war.txt | 3.2M | 2.038 seconds | 7.414 Mbytes
| unordered | beowulf.txt | 295K | 0.151976 seconds | 3.085938 Mbytes
| unordered | pride.txt | 710K | 0.331949 seconds | 3.355469 Mbytes
| unordered | war.txt | 3.2M | 1.388 seconds | 7.887 Mbytes
| chained | beowulf.txt | 295K | 0.189970 seconds | 7.304688 Mbytes
| chained | pride.txt | 710K | 0.464929 seconds | 21.83593 Mbytes
| chained | war.txt | 3.2M | 1.956 seconds | 80.988 Mbytes
| open | beowulf.txt | 295K | 0.146976 seconds | 3.468750 Mbytes
| open | pride.txt | 710K | 0.357944 seconds | 8.457031 Mbytes
| open | war.txt | 3.2M | 1.480774 seconds | 28.929688 Mbytes

4. The time efficiency of each backend was very similar for unordered, chained, and open. However chained and open used significantly more memory than unordered, probably because chained and open required multiple arrays to resize.

	The load factor and file size, in general, increased the time and memory required for chained and open. In fact, as load factor reached 1.0, open had INFINITY time for large NITEMS, showing that it became significantly less efficient than when its load factor was less than 1.0 smaller. Interestingly, the difference in time for chained as load factor increased varied, possibly indicating that it does not have as large of an impact. 
	
	Of the eight backends, unordered seems the best because it not only has very good time efficiency, it is also very efficient in memory usage. Furthermore, it is significantly easier to implement since an unordered_map is a container built into c++.
	
Andrew Paek (apaek1): Coded open.cpp, created the shell scripts to time the backends, and answered the questions in the README.

Emily Park (epark3): Coded unordered, chained, frequencies,and map_bench.

