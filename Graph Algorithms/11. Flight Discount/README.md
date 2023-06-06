# Flight Discount







* **Time limit:** 1.00 s
* **Memory limit:** 512 MB



Your task is to find a minimum-price flight route from Syrj�l� to Mets�l�. You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.



**Input**



The first input line has two integers $n$ and $m$: the number of cities and flight connections. The cities are numbered $1,2,\ldots,n$. City 1 is Syrj�l�, and city $n$ is Mets�l�.



After this there are $m$ lines describing the flights. Each line has three integers $a$, $b$, and $c$: a flight begins at city $a$, ends at city $b$, and its price is $c$. Each flight is unidirectional.



You can assume that it is always possible to get from Syrj�l� to Mets�l�.



**Output**



Print one integer: the price of the cheapest route from Syrj�l� to Mets�l�.



When you use the discount coupon for a flight whose price is $x$, its price becomes $\lfloor x/2 \rfloor$ (it is rounded down to an integer).



**Constraints**


* $2 \le n \le 10^5$ 
* $1 \le m \le 2 \cdot 10^5$ 
* $1 \le a,b \le n$ 
* $1 \le c \le 10^9$ 

**Example**



Input:

```
3 4
1 2 3
2 3 1
1 3 7
2 1 5
```



Output:

`2`


