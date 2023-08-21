### Callgrind profajler

U ovom direktorijumu se nalazi skripta za izvršavanje *Callgrind* profajlera i, opciono, alata *Kcachegrind* za pregledan prikaz profila.

Skripta kojom se pokreće *Callgrind* je `run_callgrind.sh` . 

**Uslovi za pokretanje:** 

* Proverite da li je projekat koji je testiran preuzet i da li se nalazi na odgovarajućoj putanji u odnosu na test projekat. (preuzeti projekat bi trebalo da se nalazi na putanji ``../../``)
* Ukoliko nije preuzet projekat, možete ga preuzeti sa linka datom u glavnom `README.md` fajlu celog projekta.
* *QT* na mašini na kojoj želite da pokrenete
* Postavite prava pristupa: `chmod u+x run_callgrind.sh`

#### Upotreba

Skriptu svakako pokrećete sa bar jednom od opcija kojom naznačavate da li posle pokretanja *Callgrind*-a želite da odmah pokrenete *Kcachegrind*.
 
* `-k` - pokrećete *Kcachegrind*
* `-c` - ne pokrećete *Kcachegrind*, ali je izveštaj svakako sačuvan u datoteci i možete naknadno posle da ga prikažete u ovom ili nekom drugom alatu

```
./run_callgrind -c
```

Pored obavezne opcije, možete zadati i još jedan argumenat koji predstavlja ime datoteke u koju želite da bude upisan izveštaj.
Ako ga ne navedete, izveštaj će podrazumevano biti upisan u datoteci `callgrind_output.txt` .

```
./run_callgrind.sh -k other_name.txt
```

