# 🎩 Analiza projekta Monopol 

Analiza projekta u okviru kursa Verifikacija softvera

🎓 Milena Stojić, 1024/2021

### Opis projekta koji smo analizirali

*Monopol* je studentski projekat raden na kursu *Razvoj softvera* u školskoj 2018/2019 godini. Projekat je raden u programskom jeziku
*C++* u *QT* radnom okviru. Predstavlja implementaciju stare popularne igre Monopol. Implementirana je da oponaša sve funkcionalnosti ove igre, a igrač može igrati partiju igre protiv računara.

* <a href = "https://github.com/MATF-RS19/RS019-monopol/"> Link ka Github repozitorijumu projekta </a>
* <a href = "https://github.com/MATF-RS19/RS019-monopol/tree/15a010f4e6e3571ed55d7ddf18a0ed1c5005d2f0"> Link ka grani projekta koji se analizira </a>

Cilj analize ovog projekta je bio pronalazak eventualnih bagova, uskih grla programa i delova izvornog koda koji bi mogli da se isprave.
Izveštaji upotrebe svakog alata se nalaze u direktorijumu sa odgovrajućim imenom, a jedinični testovi se nalaze unutar `UnitTestsForMonopol` test-projekta unutar direktorijuma sa istim imenom.
Detaljan opis analize se može pronaći u datoteci `ProjectAnalysisReport.pdf`, a sve slike i snimke ekrana je moguće naći u okviru  `Images` direktorijuma. 

### Spisak pronađenih bagova i uskih grla

* detektovano je curenje memorije
* pronađene su upotrebe neinicijalizovanih vrednosti i neke vrednosti se nikada ne upotrebljavaju

Osim navedenih nedostataka, program se ispravno ponaša i u skladu sa specifikacijom.




