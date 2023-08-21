# 🎩 Analiza projekta Monopol 

Analiza projekta u okviru kursa Verifikacija softvera

🎓 Milena Stojić, 1024/2021

### Opis projekta koji smo analizirali

*Monopol* je studentski projekat raden na kursu *Razvoj softvera* u školskoj 2018/2019 godini. Projekat je raden u programskom jeziku
*C++* u *QT* radnom okviru. Predstavlja implementaciju stare popularne igre Monopol. Implementirana je da oponaša sve funkcionalnosti ove igre, a igrač može igrati partiju igre protiv računara.

* <a href = "https://github.com/MATF-RS19/RS019-monopol/"> Link ka Github repozitorijumu projekta </a>
* <a href = "https://github.com/MATF-RS19/RS019-monopol/tree/15a010f4e6e3571ed55d7ddf18a0ed1c5005d2f0"> Link ka grani projekta koji se analizira </a>

Cilj analize ovog projekta je bio pronalazak eventualnih bagova, uskih grla programa i delova izvornog koda koji bi mogli da se poboljšaju.
Izveštaji upotrebe svakog alata, kao i skripte kojim se mogu ti alati ponovo pokrenuti zajedno sa `README` fajlovima se nalaze u direktorijumima sa odgovarajućim imenima, a jedinični testovi zajedno sa skriptom za njihovo pokretanje i `README` fajlom se nalaze unutar `UnitTestsForMonopol` test-projekta unutar direktorijuma sa istim imenom.

Detaljan opis analize se može pronaći u datoteci `ProjectAnalysisReport.pdf`, a sve slike i snimke ekrana je moguće naći u okviru  `Images` direktorijuma. 

### Spisak alata koji su korišćeni u analizi projekta

* **QTTest** za jedinično testiranje funkcija u projektu
* **Valgrind** alati za profajliranje
   - Memcheck
   - Massif
   - Callgrind
* **Clang-Tidy** analizator za statičku analizu izvornog koda

### Spisak pronađenih bagova i uskih grla

* detektovano je curenje memorije
* pronađene su upotrebe neinicijalizovanih vrednosti i neke vrednosti se nikada ne upotrebljavaju

Osim navedenih nedostataka, program se ispravno ponaša i u skladu sa specifikacijom.

<div style = "text-align: center">
<img src = "https://github.com/MATF-Software-Verification/2023_Analysis_Monopol2/blob/main/Images/monopol_board.jpg" style = "width: 400px;" /></div>




