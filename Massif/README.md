### Massif profajler

U ovom direktorijumu se nalazi skripta za izvršavanje *Massif* profajlera i, opciono, programa *ms_print* za prikaz izveštaja.

Skripta kojom se pokreće *Massif* je `run_massif.sh` . 

**Uslovi za pokretanje:** 

* Proverite da li je projekat koji je testiran preuzet i da li se nalazi na odgovarajućoj putanji u odnosu na test projekat. (preuzeti projekat bi trebalo da se nalazi na putanji ``../../``)
* Ukoliko nije preuzet projekat, možete ga preuzeti sa linka datom u glavnom `README.md` fajlu celog projekta.
* * Prevedite program u **debug** režimu:
   - pozicionirajte se u direktorijum projekta `RS019-Monopol` , a zatim prevedite program komandama
   -  ```
         qmake CONFIG+=DEBUG
         make
      ```
* *QT* na mašini na kojoj želite da pokrenete
* Takođe, proverite da li imate odgovarajuće podešavanje u vašem Shell interpreteru. Naime, bez ovog podešavanja imaćete *segmentation fault* na samom početku i nećete moći da primenite alat. Proverite konfiguracioni fajl Vašeg interpretera (često je to `.bashrc` fajl), i ukoliko nema, dodajte sledeću liniju: `export LIBGL_ALWAYS_SOFTWARE=1`
* Postavite prava pristupa: `chmod u+x run_callgrind.sh`

#### Upotreba

Skriptu svakako pokrećete sa bar jednom od opcija kojom naznačavate da li posle pokretanja *Massif*-a želite da kreirate izveštaj sa komandom *ms_print*.
 
* `-m` - pokrećete i *ms_print*
* `-c` - ne pokrećete *ms_print*, ali je izlaz iz *Massif*-a svakako sačuvan u datoteci `massif-output.txt` i možete naknadno posle da ga prikažete u ovom ili nekom drugom alatu

```
./run_massif.sh -c
```

Pored obavezne opcije, možete zadati i još jedan argumenat koji predstavlja ime datoteke u koju želite da bude upisan izveštaj dobijen alatom *ms_print*.
(ukoliko date opciju `-c`, taj argument se ignoriše)
Ako ga ne prosledite, izveštaj će podrazumevano biti upisan u datoteci `ms-massif-output.txt` .

```
./run_massif.sh -m other_name.txt
```

