### Callgrind profajler

U ovom direktorijumu se nalazi skripta za izvršavanje *Callgrind* profajlera i, opciono, alata *Kcachegrind* za pregledan prikaz profila.

Skripta kojom se pokreće *Callgrind* je `run_callgrind.sh` . 

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

Skriptu svakako pokrećete sa bar jednom od opcija kojom naznačavate da li posle pokretanja *Callgrind*-a želite da odmah pokrenete *Kcachegrind*.
 
* `-k` - pokrećete *Kcachegrind*
* `-c` - ne pokrećete *Kcachegrind*, ali je izveštaj svakako sačuvan u datoteci i možete naknadno posle da ga prikažete u ovom ili nekom drugom alatu

```
./run_callgrind.sh -c
```

Pored obavezne opcije, možete zadati i još jedan argumenat koji predstavlja ime datoteke u koju želite da bude upisan izveštaj.
Ako ga ne navedete, izveštaj će podrazumevano biti upisan u datoteci `callgrind_output.txt` .

```
./run_callgrind.sh -k other_name.txt
```

