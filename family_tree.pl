# current scenario: family tree

"""
    complexity of the family tree is 5>
    there will be greate grandfather and greate grandmother
    there will be grandfather and grandmother also would be greate unclue and aunt
    there will be father and mother also would be uncle and aunt from each side of the family
    there will be son and doughter and son's wife and doughter's husband and also cousine and cousine's wife and sibiling
    there will be grand son and grand doughter and grand son's wife and grand doughter's husband and nephew and niece

    image for this family tree scenario description: https://www.istockphoto.com/vector/family-tree-genealogy-diagram-pictogram-gm450540265-24669323
    the whole idea is with prespective of husband write below father and mother
"""

# state the facts depening on the complexity of the family tree

# defined for greate grandfather and grandmother
male(abreham).
female(yeshi).

# defined for greate uncle and aunt
male(alemu).
female(alemenesh)

# defined for grandfather and grandmother
male(kebede).
female(berkitu).

# defined for father and mother
male(yohanes).
female(fkr).

# defined for uncle and aunt 
male(abebe).
male(tamerat).
male(wondwesen).
female(kalkidan).
female(mantegbosh).



# defined for my self and wife
male(mekdim).
female(sari).

# defined for brother and sister in law or brother's wife
male(yeabsira).
female(nuhamin).

# defined for sister and brother in law or sister's husband
male(buze).
female(binni).

# defined for cousine and cousine's wife
male(jocy).
female(meron).

# daughter and son
male(nati).
female(nati).


# define for nephew and niece from bother brother and sister
# from brother side 
male(girma).
female(berut).

# from thier sister side
male(mikiyas).
femalte(mesi).


# define for grand cousin
male(natanim).



# define the parent and child relationship
# abreham and yeshit is parent of kebede

parent(abreham, kebede).
parent(yeshi, kebede).

parent(abreham, alemu).
parent(abreham, alemenesh).
parent(yeshi, alemu).
parent(yeshi, alemenesh).

# grand parents and thier children from both side of the family
# TBD: leave the wife of the grand father since it will increse the complexity of the family tree just stick with the male tree maybe later TBC maybe later
# kebede married with berkitu and they have children
parent(kebede, yohanes).
parent(berkitu, yohanes).

# also relate the uncle and autns because they are the children of the grand parents
parent(kebede, abebe).
parent(kebede, tamerat).
parent(kebede, wondwesen).
parent(kebede, kalkidan).
parent(kebede, mantegbosh).


parent(yohanes, mekdim).
parent(fkr, mekdim).


# relate the brother and sister in law
parent(yohanes, yeabsira).
parent(yohanes, binni).

# relate the cousin and cousin's wife
parent(abebe, jocy).

# relate the daughter and son
parent(mekdim, nati).

# relate the nephew and niece from bother brother and sister
# from brother side 
parent(yeabsira, girma).
parent(yeabsira, berut).

# from their sister side
parent(binni, mikiyas).
parent(binni, mesi).

# relate the grand cousin
parent(jocy, natanim).




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

% Rule for brother
brother(X, Y) :-
    male(X),
    parent(Z, X),
    parent(Z, Y),
    X \= Y.

% Rule for sister
sister(X, Y) :-
    female(X),
    parent(Z, X),
    parent(Z, Y),
    X \= Y.

% Rule for cousin
cousin(X, Y) :-
    parent(Z, X),
    parent(W, Y),
    (brother(Z, W); sister(Z, W)).

% Rule for nephew
nephew(X, Y) :-
    male(X),
    parent(Z, X),
    (brother(Z, Y); sister(Z, Y)).

% Rule for niece
niece(X, Y) :-
    female(X),
    parent(Z, X),
    (brother(Z, Y); sister(Z, Y)).

















