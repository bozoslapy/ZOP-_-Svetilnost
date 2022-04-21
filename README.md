Delovanje naprave --> Naprava se uporablja za namen merjenja svetilnosti. Poda nam številko, ki je v enoti LUX. Več kot je prisotne svetlobe večje je število LUX-ov. Za merjenje sva uporabila photoresistor. Naprava ima območje od 0 do 800 LUX. 


Uporabljeni material --> 9V baterija, Arduino Uno, OLED zaslon, photoresistor, 3x distančniki, 3x matice, 3x vijaki, ploščica za spajkanje,  upor 1000E, Žičke, printer kabel, kabel za povezavo z baterijo, 2x ploskev pleksi stekla.

   
Komentar nad delovanjem --> Merska napaka naprave je od 1 do 50 LUX. Problem uporabe photoresistorja je, da ima zelo majhno maksimalno izmerjavo LUX-sov. Bolje bi bilo če bi uporabljali BH1750, zato da bi imel bolj natančne in večje zmogljivosti merjenja LUX. Za kalibracijo senzorja sva v kodi dodala odštetek -100 LUX, zato ker je drugače prevelika merska napaka.


Shema vezave -->
![Shema vezave](https://raw.githubusercontent.com/bozoslapy/ZOP-_-Svetilnost/main/Posnetek%20zaslona%202022-04-21%20094706.png)


3D- model -->
![3D- model](https://raw.githubusercontent.com/bozoslapy/ZOP-_-Svetilnost/main/Posnetek%20zaslona%202022-04-21%20094901.png)

