# Programming_Exam
In questa relazione siamo andati a studiare il comportamento di un'epidemia attraverso la progettazione di un codice in linguaggio C++ che ne riproducesse la proliferazione secondo il modello SIR.

Il modello SIR, come già si può intuire dal nome, si basa su tre compartimenti distinti:
S = Suscettibili, ovvero le persone che si possono infettare;
I = Infetti, ovvero le persone contagiate e che diffondono l'infezione;
R = Rimossi, ovvero le persone guarite, decedute o in isolamento, che non possono più né infettarsi né infettare.

Il numero di persone N della popolazione è costante, perciò valgono le seguenti espressioni
    N=S(t)+I(t)+R(t)    

Lo stato di una persona può andare solo in un verso S-->I-->R

L'evoluzione della malattia in modello SIR è descritta dalle seguenti equazioni differenziali riportate all'interno del codice. \beta \in [0,1] è una misura della probabilità di contagio in seguito a contatti tra infetti e suscettibili, mentre \gamma \in [0,1] è la probabilità di guarigione (o morte) di un infetto ed è l'inverso del tempo medio di risoluzione dell'infezione.
