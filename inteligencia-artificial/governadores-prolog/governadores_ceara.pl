governou(gonzaga_mota, 1983, 1987).
governou(tasso_jereissati, 1987, 1991).
governou(ciro_gomes, 1991, 1994).
governou(lucio_alcantara, 2003, 2007).
governou(cid_gomes, 2007, 2011).
governou(camilo_santana, 2019, 2022).

governo(Politico, Ano) :-
    governou(Politico, AnoInicio, AnoFim),
    Ano >= AnoInicio,
    Ano =< AnoFim.
