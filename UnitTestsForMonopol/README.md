### Jedinični testovi u QTTest biblioteci

U ovom direktorijumu se nalazi projekat sa jediničnim testovima kojima je testiran projekat "Monopol".

Skripta kojom se mogu pokrenuti testovi iz terminala je `run_tests.sh` . 

**Uslovi za pokretanje:** 

* Proverite da li je projekat koji je testiran preuzet i da li se nalazi na odgovarajućoj putanji u odnosu na test projekat. (preuzeti projekat bi trebalo da se nalazi na putanji ``../../``)
* Ukoliko nije preuzet projekat, možete ga preuzeti sa linka datom u glavnom `README.md` fajlu celog projekta.
* *QT* na mašini na kojoj želite da pokrenete
* Postavite prava pristupa: `chmod u+x run_tests.sh`

Skriptu možete pokrenuti sa argumentom kojim zadajete ime datoteke u kojoj želite da se sačuvaju rezultati izvršavanja testova.

```
  ./run_tests.sh results.txt
```

Možete je pokrenuti i bez argumenata, tada datoteka sa rezultatima dobija podrazumevano ime `test_results.txt`.

```
  ./run_tests.sh
```

