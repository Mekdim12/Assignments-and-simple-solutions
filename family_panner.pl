
/*
    complexity of the family tree is 3
    Problem statement:
        grand parent have only one son 
        the son married to wonan who have 2 other sibiling
        the son have 5 children
        the children have childrens as well

*/


/*
 :TBR for parental relation
alemnesh is mirat for endrie and zemuye 
tsion , misrak, aster are mirat for mohommed and alemenesh

dula is uncle for sisay, ashenafi, embet, belay, dagim, sara
getenesh is aunt for sisay, ashenafi, embet, belay, dagim, sara

endrie grand father for sisay, ashenafi, embet, belay, dagim, sara
zemuye grand mother for sisay, ashenafi, embet, belay, dagim, sara

mohoammed is grandfather for befikir, eldana, amen, aklesiya, samuel, abenezer, yeabkal, soliyana, markonal
alemnesh is grandmother for befikir, eldana, amen, aklesiya, samuel, abenezer, yeabkal, soliyana, markonal

endrie great grand father for befikir, eldana, amen, aklesiya, samuel, abenezer, yeabkal, soliyana, markonal
zemuye great grand mother for befikir, eldana, amen, aklesiya, samuel, abenezer, yeabkal, soliyana, markonal

ashenafi, belay, dagim are uncle for befikir, eldana, amen
sara, embet are aunt for befikir, eldana, amen

sisay , ashenafi, belay, dagim are uncle for markonal
sara is aunt for markonal

sisay, belay , dagim  uncle for aklasiya , samuel, abenezer
sara,  emebet  are aunt for aklasiya , samuel, abenezer

sisay, ashenafi,  dagim are uncle for yeabkal, soliyana
sara,  emebet  are aunt for yeabkal, soliyana

*/

% for defining the relationship caluses in not contigous way because for readbaility its better to define the relationship in this way
:- discontiguous male/1.
:- discontiguous female/1.
:- discontiguous parent/2.
:- discontiguous sibling/2.

% grand father and mother
male(endrie).
female(zemuye).

% father and mother
male(mohommed).
female(alemenesh).

%  uncle and aunt in mothers side 
male(dula).
female(getenesh).  % I assume you meant to use female/1 here

% childrens of mohommed and alemenesh
male(sisay).
male(ashenafi).
female(emebet).
male(belay).
male(dagim).
female(sara).

% sisay married to tsihon
female(tsihon).

% ashenafi married to misrak 
female(misrak).

% belay married to aster
female(aster).

% sisay and tsihon children
male(befikir).
female(eldana).
male(amen).

% ashenafi and misrak children
female(aklesiya).
male(samuel).
male(abemezer).

% embet child
male(markonal).

% belay and aster children
male(yeabkal).
female(soliyana).

%  define the relationship between the family members
%  1st level of the family
parent(endrie, mohommed).
parent(zemuye, mohommed).

% grand father and mother
male(endrie).
female(zemuye).

% father and mother
male(mohommed).
female(alemenesh).

%  uncle and aunt in mothers side 
male(dula).
aunt(getenesh).


% childrens of mohommed and alemenesh
male(sisay).
male(ashenafi).
female(emebet).
male(belay).
male(dagim).
female(sara).



% sisay and tsihon children
male(befikir).
female(eldana).
male(amen).

% ashenafi and misrak children
female(aklesiya).
male(samuel).
male(abemezer).

% embet child
male(markonal).


% belay and aster children
male(yeabkal).
female(soliyana).



%  define the relationship between the family members
%  1st level of the family
parent(endrie, mohommed).
parent(zemuye, mohommed).


% 2nd level of the family
parent(mohommed, sisay).
parent(alemenesh, sisay).

parent(mohommed, ashenafi).
parent(alemenesh, ashenafi).

parent(mohommed, embet).
parent(alemenesh, embet).

parent(mohommed, belay).
parent(alemenesh, belay).

parent(mohommed, dagim).
parent(alemenesh, dagim).

parent(mohommed, sara).
parent(alemenesh, sara).

% 3rd level of the family
%  family of sisays

parent(sisay, befikir).
parent(tsihon, befikir).

parent(sisay, eldana).
parent(tsihon, eldana).

parent(sisay, amen).
parent(tsihon, amen).


% family of ashenafi
parent(ashenafi, aklesiya).
parent(misrak, aklesiya).

parent(ashenafi, samuel).
parent(misrak, samuel).

parent(ashenafi, abenezer).
parent(misrak, abenezer).


% family of belays
parent(belay, yeabkal).
parent(aster, yeabkal).

parent(belay, soliyana).
parent(aster, soliyana).

% family of embets
% she is single mother 

parent(embet, markonal).



% hardcoded relationship because the name of the parent
% TBD: know issue for resloving the parent of the mother side  of family
sibling(dula, getenesh).
sibling(dula, almnesh).
sibling(getenesh, almnesh).


% ======> define the rules for the relationship <=======

mirat(X, Y) :-
    female(X),
    parent(X, Z),
    parent(Y, Z),
    X \= Y.

% Rule for uncle
uncle(X, Y) :-
    male(X),
    parent(Z, Y),
    parent(W, Z),
    parent(W, X),
    X \= Z.

% Rule for aunt
aunt(X, Y) :-
    female(X),
    parent(Z, Y),
    parent(W, Z),
    parent(W, X),
    X \= Z.

% Rule for grandfather
grandfather(X, Y) :-
    male(X),
    parent(X, Z),
    parent(Z, Y).

% Rule for grandmother
grandmother(X, Y) :-
    female(X),
    parent(X, Z),
    parent(Z, Y).

% Rule for great grandfather
great_grandfather(X, Y) :-
    male(X),
    parent(X, Z),
    parent(Z, W),
    parent(W, Y).

% Rule for great grandmother
great_grandmother(X, Y) :-
    female(X),
    parent(X, Z),
    parent(Z, W),
    parent(W, Y).

% Rule for sibiling
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

% Rule for sister 
sister(X, Y) :- female(X), sibling(X, Y).

%  Rule for brother
brother(X, Y) :- male(X), sibling(X, Y).





% ====> descriptive response deined as rules <====

% Function to find of fatrter
find_father(Person, Father) :-
    findall(F, (parent(F, Person), male(F)), Fathers),
    member(Father, Fathers).

% Function to find mother
find_mother(Person, Mother) :-
    findall(M, (parent(M, Person), female(M)), Mothers),
    member(Mother, Mothers).

% Function to find list of aunts
find_aunts(Person, Aunts) :-
    findall(Aunt, aunt(Aunt, Person), Aunts).

find_uncles(Person, Uncles) :-
    findall(Uncle, uncle(Uncle, Person), Uncles).

% Function to find of siblings
find_siblings(Person, Siblings) :-
    findall(Sibling, sibling(Sibling, Person), Siblings).





% konjo remove this before submit example queries elegant one should return name or (list of name)of requested person accorind to the relationship and gender
/*
parent(Mother, sara), female(Mother).
parent(Father, sara), male(Father).
find_siblings(sara, Siblings).
find_uncles(sara, Uncles).
find_aunts(sara, Aunts).
find_mother(sara, Mother).
find_father(sara, Father).

*/
% konjo the rest of rules are relatively easy to figure out eshe just query brother(someone , tosomeone)
