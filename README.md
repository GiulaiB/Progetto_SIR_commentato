# Programming_Exam
In questa relazione siamo andati a studiare il comportamento di un'epidemia attraverso la progettazione di un codice in linguaggio C++ che ne riproducesse la proliferazione secondo il modello SIR.

Il modello SIR, come già si può intuire dal nome, si basa su tre compartimenti distinti:
\begin{enumerate}
    \item $S$ = Suscettibili, ovvero le persone che si possono infettare;
    \item $I$ = Infetti, ovvero le persone contagiate e che diffondono l'infezione;
    \item $R$ = Rimossi, ovvero le persone guarite, decedute o in isolamento, che non possono più né infettarsi né infettare.
\end{enumerate}
Il numero di persone $N$ della popolazione è costante, perciò valgono le seguenti espressioni
\begin{subequations}
    \begin{align}
        N=S(t)+I(t)+R(t)\\
        S,I,R \in N
    \end{align}    
\end{subequations}
Lo stato di una persona può andare solo in un verso, ovvero $S \longrightarrow I$ e successivamente $I \longrightarrow R$. L'evoluzione della malattia in modello SIR è descritta dalle seguenti equazioni differenziali
\begin{subequations}
    \begin{align}
        \frac{dS}{dt}=-\beta \frac{S}{N}I\\
        \frac{dI}{dt}=-\beta \frac{S}{N}I - \gamma I\\
        \frac{dR}{dt}=-\gamma I
    \end{align}
\end{subequations}\\
dove $\beta \in [0,1]$ è una misura della probabilità di contagio in seguito a contatti tra infetti e suscettibili, mentre $\gamma \in [0,1]$ è la probabilità di guarigione (o morte) di un infetto ed è l'inverso del tempo medio di risoluzione dell'infezione.

Discretizzando le equazioni differenziali appena citate, posto $\Delta t=1$, avremo
\begin{subequations}
    \begin{align}
        S_i=S_{i-1}-\beta\frac{S_{i-1}}{N}I_{i-1}\\
        I_i=I_{i-1}+\beta\frac{S_{i-1}}{N}I_{i-1}-\gamma I_{i-1}
        R_i=R_{i-1}+\gamma I_{i-1}
    \end{align}
\end{subequations}
