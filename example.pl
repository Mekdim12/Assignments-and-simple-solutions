/* Facts */
male(bob).
male(john).
male(mike).
male(jack).
male(bill).

female(lisa).
female(sarah).
female(emma).
female(jane).

parent(bob, john).
parent(bob, mike).
parent(lisa, john).
parent(lisa, mike).
parent(john, sarah).
parent(jane, sarah).
parent(jack, emma).
parent(sarah, emma).
parent(jack, bill).
parent(sarah, bill).

/* Rules */
father(X, Y) :- male(X), parent(X, Y).
mother(X, Y) :- female(X), parent(X, Y).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
brother(X, Y) :- male(X), sibling(X, Y).
sister(X, Y) :- female(X), sibling(X, Y).
grandparent(X, Z) :- parent(X, Y), parent(Y, Z).
ancestor(X, Z) :- parent(X, Z).
ancestor(X, Z) :- parent(X, Y), ancestor(Y, Z).

/* Queries */
/* Example queries:
?- father(bob, mike).
?- mother(lisa, john).
?- sibling(john, mike).
?- brother(john, mike).
?- sister(jane, sarah).
?- grandparent(bob, emma).
?- ancestor(jack, emma).
*/
