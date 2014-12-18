#Release 17 _2014-12-18_

I denne releasen har fokuset vært på utvekslingsavtaler og innholdslisten. Dette er siste releasen før jul og vi har fått inn mange saker i denne releasen. Neste release vil komme torsdag 15. januar. Den vil i stor grad inneholde fikser til utvekslingsavtalene, innholdsliste og arbeidet med ny kalender.

Diverse feilrettinger:
- Vi har skiftet toolkit for behandling av bilder som gjør at bildekvaliteten ikke skal forringes så mye som den gjorde tidligere #6787
- Det er nå mulig å legge inn ledige stillinger ved uib som et filter i brødteksten, og dermed kan uib.no/stilling nå lages på w3 #8677
- Problemer med filtrering på evu-kurslisten er nå rettet #8790
- Fjernet globalmenyen fra features slik at endringer i globalmenyen ikke blir endret ved hver oppdatering #8947
- Gjøre det mulig å oversette diverse tekster #8910 #8956
- Lenker som inneholdt query-strenger ble kuttet i "relevante lenker"-feltet på artikler, dette har vi fikset #9026

Utvekslingsavtaler
- Utvekslingsavtaler har nå fått en filterside hvor brukere kan søke etter spesifikke avtaler #8803
- Filtersiden lenker nå til korrekt avtaleside #9013
- Filtersiden har problemer med å vise alle utvekslingsavtalene så derfor har muligheten til å filtrere på studieprogram blitt fjernet. Denne vil bli lagt til igjen når problemet med visning av avtalene er løst #9031
- Alle studieprogram har fått en fane som viser hvilke utvekslingsavtaler som er tilknyttet det spesifikke studieprogrammet #8805 #9018
- Studentrapporter fra utvekslinger er nå synlige på utvekslingsavtalesiden #8808
- FS-geo-sync blir lagt til cronjobben slik at den syncer landene fra FS med jevne mellomrom #8854
- Noen endringer i redigeringsvinduet til utvekslingsavtalene #8859 #8889
- Noen utvekslingsavtaler skal ikke vise samme informasjon som alle de andre avtalene #8968
- Vise fotograffeltet på bilder på utvekslings- og studieprogramsiden #8926
- Lagt til en OU som representerer hele UiB #8933
- Skiftet url for utvekslingsavtalene #8945
- Fikset brødsmulestien for utvekslingsavtalene #8980
- Gjort endringer på visningen av studienivå som vises på avtalesiden #8981
- Varighet vises nå på avtalesiden #8982

Innholdslister
- Gjøre innholdslister synlige i innholdsvisningene i webdesken #8928
- Begrense mulighetene til å publisere innholdslister til å gjelde bare områder man er innholdsprodusent for #8929
- Gitt tilknyttet innhold i innholdslister samme funksjonalitet som tilknyttet innhold i vanlige artikler #8935
- Gjort det mulig å legge innholdslister i menyen #8936
- Fikset bylineinfo på artikler som er tilknyttet en innholdsliste #8943
- Fjernet at tittelen til tilknyttede personer vises med mindre det finnes en tilknyttet person #8944
- Gjøre område et påkrevd felt på innholdslister #9006

Kalender
- Endret datoformat på kalenderen #8938
- Gjort sql-endringer i kalender-modulen #8942

# Release 16.1 _2014-12-10_

Fikset problem som førte til at søknadsfrister for EVU-kurs utløp en dag for tidlig. #8972

# Release 16 _2014-12-04_

I denne releasen har vi hatt fokus på arbeidet med utvekslingsavtaler, jobbet videre med innholdsliste og har begynt arbeidet med ny kalender. I tillegg har vi gjort enkelte feilrettinger.

- Vi har begynt arbeidet med ny kalender #8159
- Utvekslingsavtalene skal få ny layout og visning på w3 og vi har hatt flere saker som handler om dette #8800 #8793 #8711 #8853 
- Det har blitt gjort endringer med integrasjonen mot FS på grunn av utvekslingsavtalene #8853 #8763
- Webdesk har fått noen små forbedringer #8632
- Upublisert innhold viste i innholdslisten selv når man var logget ut, dette er nå skjult for alle som ikke har en rolle i systemet #8532
- Sidebar er nå lagt til på innholdslister #8531
- Det er nå mulig å legge innholdslister inn i tilknyttet innhold #8371
- Tilknyttet innhold blir nå ikke kopiert over til en sak som blir oversatt på grunn av språkproblemer #8580
- Det har blitt gjort slik at brukere blir sendt til riktig språkversjon av webdesken når de oversetter en sak #8488
- I tillegg har det blitt lagt til litt ekstra hjelpetekst for brukere som oversetter saker #8489 

# Release 15 _2014-11-21_

R15 retter en del feil, introduserer en ny innholdstype (Innholdsliste) og gjør en del generelle endringer.

- Flytter google søket (grunnlag for søk på uib.no) til w3 fra w2 og styler dette #6486 #8613
- Gjør det mulig å legge upublisert innhold som tilknyttet innhold #6923
- Retter en stylingsak knyttet til slideshowet #7224
- Introduserer den nye innholdstypen "Innholdsliste". Denne innholdstypen kan brukes til å gi grafisk fremstilling av feks en arbeidsprosess. NB! Ikke klar til bruk enda! #7693
- Retter feil som gjorde at kulpunkt ikke fungerte på personsidene #8272
- Fjerner publikasjons-fanen for administrativt ansatte som setter antall publikasjoner i Cristin til 0 #8376
- Endrer til små bokstaver i navn på personsider #8509
- Endrer på plassering av elementer på webdesken #8510
- Oppgradering av Drupal kjerne #8616
- Retter synkronisering med sebra for at ansatte med ansettelseforhold i UNI, bare viser tittel for stilling ved UiB #7922
- Retter feil som har ført til at ansatte med to kontoer i sebra, har vist feil profil ut på ansattlister #7922
- Retter bug som gjorde at en side "hoppet" når man navigerte mellom faner #8197
- Retter feil som gjorde at Adressefelt 2 ikke vistes ut på personsider #8356
- Retter feil som gjorde at visning av data fra DBH ikke fungerte på norske sider #8381
- Retter feil som gjorde at toppen av siden ikke vistes når man navigerte via faner #8385
- Treff i autocomplete-feltet for oversettelser til en sak ble skjult av kolofon-feltet. Dette er rettet #8501
- Retter feil som gjorde at to personer med nesten likt navn hadde byttet alias fra w2 til w3 #8540
- Legger til uib.no/stillinger til w3. Skal gjøres noe mer med før den erstatter tilsvarende side på w2 #6819
- Legger til taksonomi for land/verdensdel som klargjøring til visning av utvekslingsavtaler #8387

# Release 14 _2014-11-06_

Vi gjør generelle justeringer og feilrettinger på uib.no i denne releasen.

- Det er nå mulig å finne eksternt innhold og vitnesbyrd ved hjelp av “Finn Innhold” på webdesken #4377
- Vi har startet arbeidet med en ny prosesstype som er bestilt fra ansattsidene #7694
- Alle listene som viser personer på uib.no har nå fått samme stil hvilket betyr at “tilknyttede personer” nå ser ut som ansattlistene på områder #7850
- Vi har gjort endringer på åpningstider-boksen på ub-forsiden #7888
- Level 1 har nå utvidete søkemuligheter etter filer #7902
- Feil i utlistingen av EVU-kurs er nå rettet #7985
- Små endringer inne på EVU-kursene #8177
- Vi har oppdatert Google Analyticskoden til Universal Analytics #7987
- Feil som oppstod etter oversettelse er rettet #8080
- Fjernet emne som ikke skal vise i emneoversikten #8120
- Fjernet en ekstra linje som dukket opp under studieretninger #8145
- Endret visning av studieprogram i “tilknyttet innhold” slik at disse ble mer lik vanlig innhold #8156
- Lagt til Linkedin på personsidene #8158
- Vi har oppdatert en del moduler #8181
- Endringer i datoformatene i drupal #8194
- Fikset feil hvor eksternt innhold ikke lenger var mulig å søke etter i tilknyttet innhold #8202
- Fikset en feil som gjorde at brukerne kom til feilside hvis de glemte å legge til område på en artikkel. De får nå beskjed om å fylle inn dette feltet uten å bli tatt vekk fra innholdet #8294
- Vi har gjort det mulig for områder å ha en annen postadresse enn postboks. Hvis postboks er satt til null i sebra blir besøksadressen også gjort til postadressen #8345

# Release 13.1 _2014-10-23_

Hovedfagsoppgaver som ble listet på veilederens side måtte fjernes før vi offentliggjør de nye personsidene. #8132

# Release 13 _2014-10-20_

Personsider, EVU og mindre fix og bugfix

- Tekstformateringen H3 hadde en bug i visning på pesonsidene, denne er fikset #8067
- Legger til regel om at synkronisert navn vises hvis det ikke er innhold i feltene for overskriving av navn på personsidene #8059
- Fikser funksjonen som sender deg til riktig søkeside når du klikker på et kompetansefelt #8058
- Sørger for riktig rekkefølge på personinformasjon i personlistene #8018
- Fiks for bug som oppstod der en bruker har to kontoer i Sebra #7962
- En del brukere manglet oversettelse av personsiden sin, noe som ga en del bugs, blant annet i form av at man ikke fikk overskrevet besøksadresse. Dette er fikset i #8013
- Rolle 2 kunne ved en feil kansellere/slette kontoer - denne muligheten er fjernet #8009
- Vi har satt i gang funksjonen som blokker brukere som ikke finnes i Sebra #8008
- Vi fjerner w2-synkronisering av brukere, og introduserer funksjon som lager alias/slugs i w3 for nye brukere #7995
- Fjern kolon etter "Filer"-tittel på personprofil #7716
- Ordne rekkefølge på feltene "kompetansefelt" og "Prosjekter" på personprofil #7713

- Stylingjusteringer på listen over evu-kurs #7986
- Fjerner doble headinger på evu-kurs #7866
- Gjør det mulig å søke opp emner/kurs som tilknyttet innhold basert på emnekode #7868
- Bytt "Studypoints" til "ECTS credits" på evu-kurs #7955

- Fiks for plassering av bokkarusellen på /ub-sidene #7991
- Stylingjusteringer på plasseringen av logo for spesialsamlingene på /ub "7969

- Legger til felt for påmeldingsfrist/påmelding på kalenderhendelser # 6842
- Fiks for visning av informasjon på feil språk i studieløpstabellen #7822
- Endrer "Undervisningsstart" til "Undervisningssemester" på emner #8057
- Fiks for å synliggjøre Spesialiseringsvalg på studieprogram bedre #7813

- Lar deg bare søke etter artikler på riktig språk for tilknyttet innhold #6906
- Fiks for visning av vitnesbyrd over en kolonne (tablet) #6199
- Løser bug som kuttet bilder i tilknyttet innhold i noen responsive visninger #7269
- Diverse tekniske saker #7209 #7998

# Release 12.1 _2014-10-09_

Liten release for å fikse kritiske problemer i forhold til lanseringen av nye personsider. 

- Fiks for publikasjonsfane som ikke viste riktig språk #7978
- Fiks for å hindre at level 2,3 og brukere uten rolle kan se passord, brukernavn, tilgangsgrupper og annen kontoinformasjon i redigeringsbildet til personsiden #7975
- Formatfiks for tekstfelt på persosnidene #7976
- Fiks for personside som gikk i loop #7977


# Release 12 _2014-10-08_

Vi migrerer personsidene en siste gang og gjør ferdig de siste justeringene for disse sidene i denne releasen. EVU blir også pusset på!

Saker relatert til personsidene:

- Bilde med lenke til spesialsamlingene på /UB sin områdeforside #7941
- Endelig migrasjon av innhold fra personsidene på w2 til w3 #7827
- Tilgang for level 2-brukere til å redigere andres personsider #7904
- Noen ansatte fikk telefonnumre med dobbel landkode. Dette er fikset i #7848
- Lenke til hjemmeside er nå gjemt under tittelfeltet - og tittelfeltet er default "Hjemmeside" dersom man ikke legger inn egen tittel. Vi har samtidig endret overskriften på dette feltet i edit-mode til "Hjemmeside", for at det skal korrespondere bedre med innholdet. #7690 #7872
- Lenken til CV er på samme måte nå gjemt under default tittelfelt (Vis CV) #7840
- En bug som ga html-tags i fritekstfelt på personsidene er fikset i #7183
- Personsiden speilet norsk og engelsk innhold. Dette har vi endret, slik at man nå kan ha innhold på den norske personsiden som ikke vises på den engelske #7830
- Muligheten for å redigere steders åpningstider var dukket opp via personsidene, denne er fjernet #7826
- Vi har fjernet visning av telefonnummer fra edit-siden på personsidene, ettersom disse ikke kan redigeres her #7821
- Profilbildet i edit-visningen har fått redusert størrelse #7820
- Det er gjort en liten justering i hvordan visningen av "last ned v-card" og "Logg på" vises på personsidene #7768
- Det var kommet inn en rullegardinliste for kompetansefelt på ansattlister - denne er foreløpig fjernet. Planen er på sikt å reintrodusere dette feltet som et autocomplete-felt #7761
- Noen små styling-justeringer i #7717 #7673 #7566
- Man kan nå endre navnet sitt på personsiden. I #7712 sørger vi for at en slik endring også gjenspeiles i ansattlister, tilknyttede personer og i forfatterfelt på uib.no.
- Kompetansefelt vil nå vises på personsiden i den rekkefølgen du har lagt dem inn #7710
- Vi har ryddet litt i hjelpetekstene og fjernet en overflødig redigeringsfane på personsidene i #7824 #7825
- Vi har fjernet advarslene om ikke å redigere personsidene - etter denne oppdateringen kan alle redigere! #7828

EVU, UB og generelle saker:

- Endre slik at EVU-kurs viser kontaktinformasjon til EVU #7921
- Blokk for å vise EVU-kursinstansinformasjon på EVU-kursene #7864
- Justering slik at man bare får opp kurs med kursinstanser i EVU kursoversikt når man har valgt høst/vår-filter #7767
- Styling for listen over evu-kurs #7705
- Engelsk versjon av chat til UB og en ny hjelpe-lenke på UB-søk #7581 #7234
- Filterkategoriene på emnelistene manglet oversettelse fra engelsk. Dette er fikset. #7802
- Emner har på oppdrag fra redaksjonsrådet for utdanningsinformasjon nå fått justert visningen slik at "Undervisningssemester" er omdøpt til "Undervisningsstart", og at "Antall semester" vises over informasjon om undervisningsspråk. #7765

# Release 11.1 _2014-09-23_

Fikser opp regresjon med hensyn til hvordan linkene til sosiale medier vises #7783

# Release 11 _2014-09-22_

Vi fortsetter arbeidet med EVU og personsidene, i tillegg til noen generelle fikser på sidene.

Personsider:

- Justering for bedre brukervennlighet i funksjonaliteten for emneord på personprofilsider #7294
- Endringer på listing av ansatte for å gi plass for visning av emneord #6100
- Landingsside for emneord i kompetansefelt (personlister) #6331
- Feilmelding dukket opp på personsider når person ikke hadde lagt inn RSS-feed. Dette er rettet #7583
- Lar CRIstin-feltene vise som "trekkspill"-felt #7609
- Justerer hvilke kategorier vi henter fra CRIStin, rydder i titlene og gjør den språk-avhengige #7615 #7610
- Fikser en del formateringsproblemer knyttet til visning av data fra CRIStin #7617
- Sørger for at dyplenke til CRIstin bare vises på personer som har data registrert i CRIstin #7669
- Viser "mer om stillingen"-feltet i personlistene #7657
- Styling og justering for personlistene #7659
- Retter feil i visning av sosiale medier-ikon på personkort i Chrome #7670
- Lar brukere uten rolle laste opp og slette egne filer på personsidene #7675
- Endre rekkefølgen på radene på personkortet #7689
- Juster layout for mobilvisning for personprofil slik at bildet kommer under navn og tittel #7691
- Syling og justering på personsidene #7611

EVU:

- Justering og styling i listen som viser alle evu-kurs og evu-kursinstanser #7071 #6879
- Visning av detaljer om evu-kurs-instanser på evu-kurs #6693
- Filtrer evukurs etter nivå #7052
- Justerer styling for emnelistene #7643

Diverse:

- Rettelse på feil i visning av åpningstider for UB i MSIE-9 #7577 #7658
- Synk mot FS for visning av engelske emner har feilet, dette er rettet #7671
- Retter feil som ga duplikater i personlistene #7624
- Legger til logo for OU-prosjektet i sidebar på Ansattsidene #7652
- Fjerner "Logg på"-lenken på Tilknyttede personer-visningen #7623
- Undervisningssemester viste norsk språk på engelske emnesider. Feilen er rettet #7242
- Legg til "Workshop" som arrangementstype #7616
- Ved lenking direkte til tab på side viser nå hele siden #7601
- Det var mulig å legge til sider som "søsken" til hovedmenypunkt, dette er nå fjernet #7612
- Diverse tekniske saker #7565

# Release 10 _2014-09-08_

Vi fokuserer fortsatt på person-sider og evu-området i denne releasen, samt gjør noen justeringer i ny mal for UB.

- "Rediger profilen din"-knappen som var plassert nede til høyre på personsidene, virket for dominerende og forvirrende. Vi har i stedet flyttet den inn som en tekstlenke på v-card, under "Last ned v-card", lenken. Du kan nå logge inn via denne lenken fra en hvilken som helst personprofil, og du vil bli sendt til din profilside. #7169
- Legger til rette for å inkludere rss-feed på personprofil #6428
- Legger til rette for twitter-feed på personprofil #6427
- Gjør lenken for språkbytte synligere på personprofil edit-side #7182
- Integrasjon av CRIstindata på personprofilsider #6434
- Engelske personprofiler viser engelsk navn på enhet for person #7507
- Legger til grafisk element (fargestripen) på personprofil v-card #7251
- Feltet for spesielle åpningstider på UB-området bruker nå hele bredden #7061
- Justering i design for visnings av åpningstider for bedre brukervennlighet #7161
- Legger til lenke til Google Maps under kart i åpningstider for bedre brukervennlighet #6883
- Det er lagt til en ny event-type: "Presentasjon" #7258
- Tidligere forsvant snarveien ("tannhjulet") til å redigere menyen hvis menyen hadde mindre enn fem punkter. Dette er rettet opp, slik at denne snarveien er tilgjengelig uavhengig av antall menypunkter i hovedmenyen #6930
- Vi har sjekket og dobbeltsjekket Sebra-synkronisering av brukere #7157
- Det er nå mulig å deaktivere vi-bruker-cookies-popup på sidene (spesielt med tanke på informasjonsskjermer) #6440
- Fjerner overflødige elementer for filtersiden for kurs #7515
- Fjerner tab for studieløpstabell på studieprogram når det ikke er innhold i tabellen #7213
- Skjule evu-kurs (inntil evu-kursmodul er klar) #7543
- Diverse tekniske saker #7512 #7318


# Release 9 _2014-08-26_

Denne oppdateringen gjør først og fremst ytterligere justeringer for nye personsider og EVU-sidene.

- Generell forbedring av lesbarheten og layout på personsidene #7155 #7156 #7184 #6532 #7027
- Gjør flere av feltene på personsidene til egne felt på norsk og engelske sider (oversettbare) #7029
- Oversettelse av taksonomifeltene "kompetanse" på personsidene #7196
- Endre popup-teksten for sosiale medier-ikonene fra "Følg oss på..." til "Følg meg på..." på personsidene #7180
- Default tittel på url-felt for personsidene skal være "Hjemmeside"/"Homepage" hvis ikke tittelfeltet er fylt ut #7181
- Lenken til organisasjonsenhet på personsidene skal lenke til området på uib.no #7030
- Brukere uten rolle på w3 vil nå få en verktøymeny når de logger seg inn for å redigere personprofilen sin #7206
- Kurskode skal nå vises i faktaboks på evu-kurs #7046
- Alle kurs av typen "EVU" vil nå få tittel over faktaboks: "Etter- og videreutdanningskurs" #7047
- Alle kurs/emnebeskrivelser og studieplansider vil nå ha en tittel øverst som også angir hvilket semester det gjelder for #7048
- Det er introdusert en regel for hvordan pris skal oppgis for EVU-kurs: Settes prisen i FS som et beløp, vises beløpet. Settes prisen til 0, vises det som "gratis", settes det ingenting i feltet for pris, vises teksten "Pris ikke fastsatt"#7050
- Lenke til kursbeskrivelse skal ikke visesn, når det ikke finnes noen kursbeskrivelse #7051
- Artikler uten kicker fikk brutt layout på Aktueltsidene, dette er fikset #6185
- Bytt språk-lenken på edit-sidene er tilbake på plass #6713
- Besøksadresse er lagt til i kolofonfeltet #7139
- "Det skjer" i høyre kolonne har fått tankestrek og er justert for riktig layout #7166
- Linjeavstanden i utfelt meny var for stor, denne er justert #7168
- Diverse tekniske saker #7147 #7214 #7204 #7208 #7210 #7204 #7295
- Oppdatert hjelpetekst på innloggingssiden til W2 #7186

# Release 8 _2014-08-11_

Mindre oppdatering som primært retter noen mindre feil og gjør noen oppdateringer knyttet til uib.no/ub og person-sidene. 

- Gjør e-postadressen klikkbar på OU (steder) #7060
- Gjør OU-feltene for tittel og "Custom hours" oversettbare #7059
- Retter feil i layout for uib.no/ub-malen i IE9 #7057
- Diverse justeringer på layout på personsidene #6975 #6958 #7080 #7028
- Gir feltet "Related persons" et editerbart tittelfelt #7022
- Håndterer feil i integrasjon med FS #7113
- Legger til github som mulig sosiale medier-link #7039
- Rydder opp i problemer knyttet til oversettelse av taksonomi for NUS-sidene #7004
- Retter feil i synkronisering av brukere fra Sebra #7118
- Oppdaterer til Drupal 7.31, samt moduloppgraderinger #7146
- Legger begresninger på hva brukere kan legge i html-felt for banner, spesifikt forhindre at "!important" benyttes #7053
- Fjernet bug knyttet til studiekodefilteret #7019
- Legger til ny hendelsestype: Guided tour. #7086

# Release 7.9 _2014-07-07_

Vi slipper igjennom en liten ekstra oppdatering for å rette opp noen små saker som ikke kom med i 7.8.

* Vi har fått på plass regler for hva som skal skje med områder og artikler under områder som bytter navn #4671
* Feil i filtrering på NUS-lister for studieprogram og emner gjorde at informasjon dupliserte seg selv. Dette er fikset i #6992
* Rolle 2 har nå tilgang til å redigere studieprogram, emner og åpningstider for områder #7033 #7018
* Responsiv visning av åpningstider på plass #7008 #7005
* En liten opprydning i layout på personsidene i redigeringsmodus #6399
* Og vi har fått vår egen side for disse release-notatene  <http://uib.no/webdesk/release-notes> #7054

# Release 7.8 _2014-07-02_

7.8 ble en stor oppsamlingsrelease før sommerferien. Her har vi gjort ferdig ny funksjonalitet og finpuss for Universitetsbiblioteket, lagt til rette for EVU og fortsatt justeringer på personprofil-sidene.

Ny funksjonalitet for Universitetsbiblioteket

* Rolle 2-brukere vil nå ha tilgang til å redigere Organisasjonsenheter - denne tilgangen trengs hvis man skal ta i bruke funksjonaliteten "åpningstider". Vi har også lagt til felt for organisasjonsenheter; epost og et rent tekstfelt for spesielle beskjeder angående åpningstider #6942 #6798
* Vi har laget et nytt tekstfilter som kan introduseres i html på artikkel for å vise en widget. Foreløpig er det lagt til rette for en bokwidget for Universitetsbiblioteket #6944
* Funksjonaliteten for å vise åpningstider er lagt til for Universitetsbiblioteket. Disse sakene justerer, legger til rette for riktig visning av og riktig tilgang til redigering av åpningstider på UB-siden #6943 #6869 #6881 #6899 #6863 #6860 #6990 #6872 #7007

Endringer for EVU og utdanningsinformasjon

* Feltet "undervisningssemester" vil nå etter avtale med SA gjøres synlig igjen #6941
* Rolle 2 får tilgang til å redigere NUS-sidene #6911
* "Study points" endres til "ECTS credits" på studiesidene #6908
* Vi retter en feil i integrasjonen mot FS som førte til dobbelvisning av url i studieprogram/emner #6977
* Vi henter inn informasjon for POST-studier #6859
* Evu-menyen og brødsmuler skjules inntil videre for emner knyttet til evu #6993
* Emnebeskrivelse skjule på EVU-kurssiden og flyttes til separat side, med lenke fra "Ressurser" #6691 #6690
* Velg semester-boksen samt noen andre elementer skjules for EVU-kurs #6689

Personsidene:

* Migrerer innhold av data for personsidene fra w2 (denne migrasjonen skal tas på nytt senere) #6900
* Retter feil i sebrasynkroniseringen #6951
* Du kan nå finne en person på uib ved å bruke url på formen www.uib.no/user/uib/&lt;brukernavn> #6981
* Retter og justerer rundt visning av navn og foto på personsidene #6974 #6904
* Endrer widget for opplasting av dokumenter på personsidene #6626
* Vi har i denne oppdateringen introdusert feltet "Tilknyttede personer" til artikler. Funksjonaliteten som lar deg legge til personer vha brukernavn til en liste nederst på siden på artikkel, skal ha litt mer finpuss før den er helt klar. #6945

Generelle saker og feilrettinger:

* Vi har introdusert et filter som beskytter lange dokumenter fra studiekode-filteret #7003
* Rolle 2 kan ikke lenger redigere ansatte og innholdsprodusenter i administrasjonsgrensesnittet på område #6889
* Endring i format på telefonnummer for hele uib.no #6861
* Endrer visning av "Nyheter" til ikke å vise nyheter eldre enn 4 måneder #6350
* Legger til rette for å kunne ha enda en artikkel i nyhetskarusell på område #5612
* Problemet med at man "mistet" fanene i navigering via bokmerker på siden, er fikset #6821
* Stillings-feltet i vitnesbyrd var blitt låst ved en feil, og er nå åpnet for redigering #6747
* Feil som viste html i områdetitler  er rettet #6945


# Release 7.7.1 _2014-06-11_

Retter stylingfeil som gjorde at man ikke kunne redigere i toppmeny på UB-siden #6796


# Release 7.7 _2014-06-10_

R7.7 har primært håndtert tilrettelegging for visning av EVU-kurs på w3, samt jobber videre med ny forside for Universitetsbiblioteket og nye personsider. I tillegg migrerer vi det siste området fra w2 til w3.

Diverse saker:

* Migrerer området /forskermobilitet fra w2 til w3 #6752
* Gjør noen styling-endringer i kalender-visningen #3828
* Gjør endringer i orange-fargen for å møte krav om kontrast #6714
* Skjuler feltet for "undervisningssemester" på studieprogramsidene #6774
* Gir navn til søkefeltet (universell utforming) #6772
* Retter feil som gjorde at videoer bare viste som en tynn linje på mobil #6771
* Legger til rette for å endre logoer i kolofon via funksjonaliteten "Eksternt innhold" #6473 #6788

Endringer som tilrettelegger for EVU:

* Henter EVU-kursinformasjon fra FS #6481
* Gjenopptar listing av %-F (evu) kurs igjen #6687
* Setter kategorien "EVU" for noen evu-kurs #6688
* Setter opp beta for liste over alle evu-tilbud og -kurs #6695
* Setter opp riktig brødsmulesti for evu-kurs  #6718
* Introduserer en ny artikkeltype for EVU-tilbud #6748
* Introduserer muligheten for å legge studieprogram som tilknyttet innhold til artikkel #6692

Endringer som tilrettelegger for nye personsider:

* Setter begrenset HTML som default for alle tekstfelt på personsidene #6442
* Gjør tilpasninger for vcard-feltet på personsidene #6707
* Endrer navnet på tab på personside etter hvilken type ansatt du er ("Forskning" / "Arbeid") #6708

Endringer knyttet til ny forside for UB

* Legger til funksjonalitet som gir kartvisning for kontorer/steder #6650
* Plasserer åpningstider/kontorer-feltet øverst på et område #6778
* Justerer bredde på bannerfeltet på toppen av siden (brukt som søkefelt for UB) #6623
* Gir mulighet for å bruke tabs i bannerfelt på ub-sidene #6765

# Release 7.6 _2014-05-26_

R7.6 har gjort følgende oppdateringer av systemet

Styling og justeringer:

* Justerer fargen på lenker for bedre kontrast (universell utforming) #6590
* Justering på styling på global kalender #6404
* Gir styling til nøkkeltall-informasjon som skal vises på nye sider om UiB #6368

Feilrettinger:

* Justerer antallet treff som vises i autocomplete felt når man skal velge område å publisere til. Justerer også regelen for hvilke områder man får lov til å publisere til #6520
* Retter feil i headerfeltet på uib.no/grieg #6603
* Tetter et sikkerhetshull i felt for oppretting av ny artikkel #6627
* Fjerner merket som la seg rundt meny når man klikket i hovedmeny på område – effekt av at vi har justert i muligheten for å kunne bruke tab-tast for å navigerer på sidene (universell utforming) #6483
* Setter på plass lenke for bytte av språk i webdesk (forsvant ved en feil etter forrige oppdatering) #6517
* Setter på plass “Add content”-knapp i engelsk webdesk (forsvant ved en feil etter forrige oppdatering) #6516
* Skjuler feltet for fremhevete artikler for alle områder utenom /Aktuelt, der denne funksjonen er i bruk #6401
* Retter bug i menyvelger på android enheter #6400
* Retter opp feil som gjorde at innholdet “hoppet” på siden når man byttet mellom faner i artikkel #6250

Nye funksjoner:

* Legger til funksjon som gjør at man kan laste opp flere bilder til hovedmedia på artikkel. #6485
* Legger til en ny hendelsestype (boklansering) #6266
* Legger til en statistikkside for administratorer i webdesken  #6380

* Legger til lenke til Cristin på nye personsider #6568
* Viser innholdsfaner på nye personsider #6433
* Knytter sosiale medier til nye personsider #6420
* Legger til områdetilhørigheter til nye personsider #6415
* Kombinerer Sebra-data med mulighet til å legge inn egne data på nye personsider #6412
* Legger til “Rediger din profil”-knapp på ny personside #6430
* Kombinerer nye personsider med data fra organisasjons-sted #6413

* Leverer funksjon som legger til rette for bibsys-søk i toppbanner for de nye sidene til UB #6652
* Legger til felt for book widget påny forside for UB  #5741
* Legger til live chat på ny forside for UB #5739
* Legger til funksjon for å vise åpningstider på avdelingsbiblioteker på ny forside for UB #5737
* Ny forsidemal for UB #5617

Tekniske saker:

* Oppdaterer norske oversettelser fra Drupal #6611
* Oppdaterer til Drupal 7.28 #6480
* Migrerer nye områder #5874
* Justerer filter for redigering i full html for administratorer #6634
* Fiks for feilmeldinger i log fra Drupal #6617


# Release 7.5 _2014-05-12_

R7.5 har gjort følgende oppdateringer av systemet

Generelle endringer:

* Alternativ tekst for bilder er et krav i henhold til regelverk for universell utforming av offentlige nettsteder. Derfor har vi nå gjort det obligatorisk å legge inn alternativ tekst for bilder. #6023
* Vi har endret på design for menyen på forsiden til uib.no i mobilvisning, for å bedre synlighet og tilgjengelighet på utvidet meny her. #6172
* Vi har forbedret utseende på vitnesbyrd-teaser på områdeforsiden #6205
* Vi har rettet opp i sorteringen på studieprogramlister på engelske sider, etter studienivå (oppfølgingssak etter forrige oppdatering) #6270
* Vi har fjernet alumnusdager-logoen i bunn-feltet på uib.no #6447

Feilrettinger:

* Problemer med å nå eget område via autocomplete når mange områder har lignende navn, har fått en midlertidig fiks ved å gi mulighet for å lenke direkte til "lag innhold" med forhåndsutfylt områdetilknytning. Saken vil bli fulgt opp med en mer permanent løsning senere. #6414
* Bannerfeltet som er lagt til på område for å dekke et behov i utviklingen av ny forside for UB, var synlig både alle. Feltet er nå bare gjort synlig for rolle 1 #6402
* Fiks for RSS-feed som ga feil dato i lister #6238
* Fiks for at hendelsestypen "Utstilling" skulle være synlig på alle datoer innenfor varigheten til hendelsen. Dette vil bli fulgt opp for alle hendelser senere. #6058
* Fiks for beregning av bredde på mobile enheter #3558

Endringer og ny funksjonalitet (ikke tilgjengelig for brukerne enda):

* Introduserer ny mal for personsidene #5896
* Setter opp redigeringsside for nye personsider #5897
* Fjerner sidebar for personsider #6333
* Endrer midertidig hjelpetekst/varseltekst på nye personsider #6269
* Setter inn blokk som viser DBH-tall for UiB (til uib.no/om-siden) #6269
* Introduserer modul for å vise åpningstider #6154

Migrasjon:

* Migrerer området uib.no/internasjonalt (engelsk og norsk) #6382

Diverse tekniske saker #6397 #6237 #6372 #6381 #6374 #6035

# Release 7.4 _2014-04-28_

Oppdateringen oppdaterer drupalkjerne og moduler, migrerer nye områder til w3, setter opp felt for ny områdeforside for UB, samt avslutter hovedarbeidet med utdanningssidene på w3.

* Migrerte nye områder til w3 #5873
* Sørget for at PHD-kurs også listes ut i oversiktslister over emner #6212
* Grupperte full studieprogram i lister etter studienivå #6098
* Rettet opp i regel for når "Forrige/Neste-semester" vises på emne #5922
* Rettet opp i bug i visningen av vitnesbyrd over full bredde på områdesiden #6081
* La til html-felt i toppen av områdeside (skal i første omgang benyttes på ub-området) #6170
* La til varseltekster på profilsidene for å unngå misforståelser mens vi jobber med nye personsider #6098
* Oppgradederte drupalkjerne og moduler #6275 #6158

# Release 7.3.2 _2014-04-11_

Retter opp følgefeil av #5609 hvor faner i artikler ikke var aktive når
fanetittelen inneholdt spesielle tegn #6211

# Release 7.3.1 _2014-04-10_

Retter opp følgefeil av #5854 som ga listen over institutter på områdeforsiden feil styling #6203


# Release 7.3 _2014-04-10_

Denne oppdateringen oppdaterer en del Drupalmoduler, gjør justeringer på studieprogram- og emnevisninger og introduserer de første tilretteleggingene for nye personsider på w3.
I tillegg rettes et par små feil

* NUS, studieprogram og emne-lister har fått likt utseende, tittelfelt og riktig browser-tittel #6099 #6063
* Moduloppdateringer #6155
* Endre alle emnelister slik at de viser kode først, og sorterer på denne #6106
* Endrer utseende på filter for studieprogram og emnelister for bedre plassutnyttelse #6056 #6053
* Retter opp sorteringen på studieprogram-visningen på fakultets- og instituttnivå til å sortere på bachelor - master - årststudium. #5563
* Fjerner nummer-id og retter til visning av tittel på riktig språk i filterliste for emner
* Legger til nye felt for personinformasjon og migrerer informasjon fra w2 #5903 #5904
* Retter opp layout for nyhetslister der kicker-feltet mangler #5854
* Legger til hendelsestypen "Møte" for arrangementer #4992
* Retter opp feil i utseende på hendelser av typen "Utstilling" #6017
* Legger til rette for å kunne lenke til en spesifikk h2-tab på artikkel #5609
* Retter opp feil i feltrekkefølgen på artikkel #6176
* Retter feil som gjorde at man ikke kunne legge til nytt innhold etter forrige oppdatering #6184


# Release 7.2 _2014-04-01_

R7.2 migrerer noen etterlatte områder etter MOFA + Universitetsbiblioteket. I tillegg blir det lagt opp til ny global kalender i w3, det er fortsatt arbeid på funksjonalitet for studieprogram og emnevisninger, i tillegg til at en del mindre saker fikses.

* Migrerer områder som ble glemt ved migreringen av MOFA #5973
* Migrerer Universitetsbiblioteket #6020
* Retter opp feil som har gjort at steder i w3 ikke har blitt oppdatert fra Sebra (adresseinformasjon i footer) #5942
* Endrer farge på tekst i "Viktig melding"-boksen #6068
* Viser studiespesialiseringer i studieprogram-oversiktsliste #6004
* Fjerner tomme NUS-kategorier fra NUS-listene
* Retter opp feil i kalkuleringen av varighet på studieprogram #5920
* Endrer visning av relevante studieprogram for emne til å hente alle mulige studieprogram med unntak av program der emnet er helt valgfritt #5921
* Justeringer på studiepgoram-listene #5557 #5532 #5457
* Gir tittel og justerer layout for NUS-sidene #5456
* Leverer definerte emnelister for utenlandske studenter til området utdanning #5536
* Fjerner de andre spesialiseringene fra studieløp-tabellen når en spesialisering er valgt #5387
* Setter opp global kalender i w3 #4776
* Gjør kalenderdata tilgjengelig som åpne data #4168
* Diverse små styling-saker #5926 #5927 #5901 #5394
* Tekniske saker i forbindelse med visning av studieprogram #6032
* Diverse tekniske saker #6032 #6019 # 5939 #5384


# Release 7.1.1 _2014-03-19_

Fikser linken til Alumnusdagene fra logoen nederst på hovedsiden.

# Release 7.1 _2014-03-18_

R7.1 gjør i hovedsak oppdateringer og feilrettinger knyttet til studieprogram, emner og lister på utdanningsområdet.

- Innfører dropdown filter for søk på emner og inkluderer studiepoeng i filteret #5460 #5461
- Fjerner overskrifter på infotyper på emner, dersom de ikke har noe innhold å vise #5494
- Sørger for at studieplan for riktig spesialisering vises når man har valgt spesialisering på studieprogram #5572
- Fjerner overflødige felter fra faktaboks på PHD-kurs #5727
- Endrer sorteringsrekkefølge på emner i studieløpstabellen, slik at obligatoriske emner alltid listes først #5738
- Legger til pop-up-tekst på kolonnene "S", "SP" og "A", samt forklaringstekst under i studieløpstabellen #5705 #5708
- Gjør teaser-tittelen til vitnesbyrd på studieprogram mindre #5703
- Sjekker hvor robust systemet er hvis fs-pres ikke er tilgjengelig #5487

- Bruker thumbnail-bilde på ansattlistene på område #5727
- Sørger for at navn/info alltid ligger ved siden av bildet på ansattlistene på område #2384

- Lar systemet velge det lille bildet i en sak til visning i tilknyttet innhold, dersom stort bilde mangler #5349
- Fikser utseende på tilknyttet innhold på innholdstypen vitnesbyrd #4856

- Gir mulighet til å legge meny på fagsider #5608
- Gir mulighet for fullskjermvisning i wysiwyg #5733
- Legger til google analytics-sporing på noen sider #5818
- Bytter en logo i kolofon-felt på uib.no forside #5919



# Release 7 _2014-03-12_

R7 migrerer Universitetsmuseet og Det medisinsk-odontologiske fakultet inkl
alle underområder til ny plattform. Dermed er alle seks fakulteter migrert til
Drupal.  Releasen tar også hånd om feil som oppstod i testmigrasjonen:

- MOFA hadde navigasjonssider som var knyttet opp til flere hovedmenypunkter. Dette ga uventet rekkefølge på både hovedmenypunkt og undermenypunkter etter migrasjonen. Fikset i #5853
- Feil med datoformatet dukket opp igjen og ble fikset i #5839
- Fjerner områder som IKKE skulle være med over i migrasjonen #5826
- Default status for nye artikler er "upublisert" i w3. Dette måtte det justeres for i migrasjonskoden, for at ikke alle migrerte artikler skulle få status som upublisert. #5807
- Bytte til små bokstaver i url for uib.no/fg/hlf
- Redaksjonell endring på bildetekst som var for lang #5805
- Teknisk sak #5842

# Release 6.3 _2014-03-04_

Denne releasen retter opp feil avdekket i siste runde testing for studiesidene til UiB. Den gjør også en del generelle bugfikser og stylingjusteringer.

- Viser engelsk navn på eier av studieprogram og på grad på engelske studieprogramsider #5516
- Fjerner studiekode/emnekode fra tittelfeltet på studieprogram og emner #5517
- Viser bare ett nummer i S-feltet på studieløpstabellen, dersom de dataene gir to like tall #5631
- Viser bare tall i feltet A for anbefalt semester i studieløpstabellen, dersom emnet faktisk er tilgjengelig i mer enn ett semester #5632
- Gir styling til NUS på nivå 3 #5523
- Gir styling til studieplan-sidene #5576
- Henter inn riktige infotyper til integrerte masterstudier #5725
- Sørger for at obligatoriske og valgfrie kurs sorteres hver for seg i studieløpstabellen #5521
- Tittel på NUS-sidene hadde en bug som gjorde at de alltid plukket engelsk tittel, også på norske sider. Den er fikset. #5592
- Endrer default sortering på doktorgradspressemelding til å være synkende #5606
- Skjuler datofeltet på doktorgradspressemelding #5607
- Fikser bug som skjulte "Bruk"-knappen på ansattlistene #5544
- Fikser bug som forkortet tittel-teksten i slideshowet #4064
- Setter inn ny versjon av sosiale medier-ikonene på områdeforsidene #5149
- Sørger for at vitnesbyrd-teaseren på studieprogrammene aldri viser mer enn ett bilde #5167
- Viser studiekoden i eget felt i faktaboks på studieprogram og emne #5533
- Sørger for at studieprogrammer som listes under "Emnet er en obligatorisk del av.." på emnesidene, viser engelske navn på engelske sider #5535
- Sørger for at den siste teksten i studieløp-tabellen vises (bug) #5709
- Gi utdanning/nus-siden meny for området utdanning #5462
- Fikser bug som gjorde at sider med lenker til hverandre i tilknyttet innhold ga feil på siden #5482
- Fjern "Forrige/neste"-lenke på doktorgradspressemeldingssiden, inntil gamle doktorgrader er importert i systemet #5680
- Integrasjon mot FS - viser infotyper for PHD-kurs. NB! oppfølgingssak i R7.1 for å få med all info fra tabellen også. #5722
- Sørger for at alle artikler får opprettet alias på gammel tittel, dersom de får endret tittel #5034
- Tekniske saker #5500

# Release 6.2 _2014-02-20_

Oppdateringen gjør endringer og feilrettinger på studieprogram og emnemaler.

- Fjerner lenke til studieplan når studieplan ikke finnes #5492
- Fjerner overflødig bruk av fet formatering i studieløptabellen
- Legger til globalmeny og områdemeny på studieplan og nus-sider
- Sørger for å vise informasjon for inneværende semester i studieløptabellen #5505
- Fjerner lenker til utgåtte kurs i studieløptabell #5490
- Introduserer "Study programme" lenke i tabellen til venstre på engelsk studieprogram-side (tidligere tab) #5488
- Fikser bug som gjorde at studieretningene ble publisert og avpublisert annenhver dag #5486
- Sørget for å gjøre headingen "Specialization" oversettbar #5445
- Sørger for at Timeplan og Litteraturliste blir hentet fra riktig semester #5444

Andre mindre stylingjusteringer:

- justerer bilder til å dekke høyden i uthevet felt (fjerner grå strek under bildet) #3932
- Setter kappene for "bruk" og Reset"-"Finn innhold" i webdesken på linje #5497
- Sørger for at service-ikonene til sosiale medier holdes på en linje under studieprogram i alle skjermfomater #5495

Tekniske saker: #5383, #5078


# Release 6.1 _2014-02-17_

Denne oppdateringen gjør ferdig visning av studieinformasjon for w3. All grunnleggende funksjonalitet er nå på plass, men noen deler skal få ytterligere hjelp med utseende.

Oppdateringen oppgraderer også feature-modulen til Drupal, fikser på utseende til webdesken og gjør et par andre små fikser i løsningen.

- Løser funksjonalitet og foreløpig styling for sider som viser studietilbud sortert på NUS-kode #4998 #5432 #5345 #5338 #5067 #5068 #5170 #5179
- Løser funksjonalitet og styling for studiepgram og emnevisninger #5393 #5420 #5392 #5391 #5290 #5370 #5361 #5362 #5357 #5173 #5151 #5169 #5390
- Fjerner Infotypene "Introduksjon" og "Emnebeskrivelse" fra emnevisningen #5322
- Gir studieprogram felt for å legge til flere grupper med relevante lenker med selvvalgt tittel #5250
- Setter opp en områdeside med områder gruppert etter type #5431
- Setter opp visning for studieprogram med studieretninger, samt brødsmulesti for studieretningene #4621 #5386
- Sorterer emner og studieprogram-lister etter navn og retter opp titler for listene #5333 #5331
- Endrer default status for nye artiker til å være upublisert #5351
- Fikser bug i webdesken #5310
- Fikser bug som ga migrerte hendelser uten sluttdato feil sluttdato #5301
- Diverse tekniske saker #5301 #5172 #2618 #5424 #4172
- Oppgraderer til features 2.0 #4993


# Release 6 _2014-02-05_

Release 6 migrerer Det matematisk-naturvitenskapelige fakultet med alle underområder samt to områder som manglet fra migrasjonen av Psykologisk fakultet.
Releasen håndterer også noen feil knyttet til migrasjon samt et par andre, mindre feil i produksjon.

* Migrerer Det matematisk-naturvitenskapelige fakultet #5000
* Håndterer feil knyttet til migrasjon #4787 #5259 #5260 #5262 #5365 #5268
* Migrerer områder som manglet fra migrasjon av Det psykologiske fakultet #4694
* Styling og justeringer i studieprogram- og emnevisning #4413 #5150 #5152 #5165
* Styling for informasjonskapsel-varsling i IE #4907
* Diverse tekniske saker #5249 #5246

# Release 5.3 _2014-01-28_

Releasen inneholder funksjonalitet for visning av studieprogram og emner, samt stylig for disse. Den inneholder også oppgradering av flere Drupalmoduler og fikser et par feil i løsningen. Legger også til ny logo på forsiden.

* Retter på utseende på utskrift av sider som bruker faner #4145
* Retter kolofon, slik at den viser adresse til området, ikke bare sentral adresse #3902
* Retter opp feil som har oppstått med ujevne mellomrom der faner på infosider har forsvunnet #2542
* Fjerner understreking på lenker i brødsmulesti og faner #4945 
* Diverse styling knyttet til studieprogram og emner #5111 #5131 #5110 #5109 #5058 #4967 #4965 #4963 #4962 #4959 #4952 #4964
* Diverse funksjonalitet knyttet til studieprogram og emner #4991 #4724 #4306 #4622 #4941 #4699 #4943 #4609 #4950 #4966
* Legger til BSRS logoen til forsiden #4989
* Rydder i styling til de nye sidene for phd-pressemeldinger #4946
* Oppgraderinger av Drupal-moduler #4957 #4950 #4956
* Fuksjonalitet knyttet til visning av studieprogram sortert etter NUS-kode #5040 #3820 #4996
* Andre tekniske saker #4995 #4997


# Release 5.2 _2014-01-10_

Releasen inneholder funksjonalitet for visning av studieprogram og emner, samt stylig for disse, implementerer også en ny innholdstype og område for nye doktorgrader og migrerer områdene uib.no/project/speakup og diverse områder tilknyttet Kommunikasjonsavdelinga.

* Bug med lenker til studieprogram og emner i tekst, samt bug knyttet til h2-tab filter er fikset  #4782 #4877
* Bug som forårsaket at saker mistet forfatter (byline) etter migrasjon. #4707
* Migrert området uib.no/prosjekt/speakup #4693
* Migrert områder tilknyttet Kommunikasjonsavdelingen #4757
* Introduserer ny artikkeltype for doktorgradspressemeldinger, samt område som lister og viser disse #3472 #4931
* Forbedrer visuell utforming av lenker i tekst #4211
* Diverse saker knyttet til funskjon og styling av studieprogram og emner #4304 #4873 #4860 #4767 #4725 #4645
* Legger meny-tab til innholdstypen vitnesbyrd #4680
* Oppdaterer service-link ikonet for Google+ #4723
* Moduloppgraderinger i Drupal #4855

# Release 5.1 _2013-12-16_

R5.1 inneholder saker der vi fortsetter å legge til rette for å vise studieprogrammer og emner på ny plattform. I tillegg har vi lagt inn varsel om informasjonskapsler på uib.no, ryddet i mobilvisningen av arrangementer i slideshow og hardkodet logo for På høyden på uib.no/aktuelt.

* Lagt til varsel for informasjonskapsler på uib.no #3949
* Tatt bort faktainformasjon fra visning av arrangementer i slidshow på mobil #3559
* Plassert På høyden-logo i sidebar på uib.no/aktuelt
* Diverse saker som forbereder visning av studieprogrammer og emner på uib.no #4287 #4305 #4308 #4536 #4604 #4605 #4640 #4642 #4643 #4644 #4652 #4702 #4704

# Release 5 _2013-12-02_

R5 migrerer området /utdanning, /ua (studieadministrativ avdeling og /laererutdanning til ny plattform. I tillegg fortsetter vi å legge til rette for å vise studieprogrammer og emner på ny plattform.

* Migrerer bilder fra studieprogramsidene på w2 #4494
* Lager en visning for studieprogrammer A-Å #4313
* Lager et filter for å vise lenker til studieprogrammer og emner i løpende tekst #4290
* Definerer brødsmulesti for studie-program og emner #4458
* Diverse saker som forbereder visning av studieprogrammer og –emner i w3 #4289 #4295 #4301 #4302 #4303 #4452 #4357 #4477 #4600 #4602 #4603 #4526
* Oppdaterer språkmodulen i Drupal #3967
* Migrerer området utdanning #4212
* Retter feil i migrasjonskode #4601 #4608
* Retter opp feil i brødsmulesti for hendelser #4527


# Release 4.3 _2013-11-25_

Forberedende saker til migrasjon av området /utdanning samt sikkerhetsoppdatering av moduler i drupal, bla core.

* Flyttet "Kontakt"-info fra studieinnholdsfeltet til venstre infofelt #4292
* Legger til service-links for deling på sosiale medier for studieinformasjon #4414
* Oppretter nye felt for studierelatert informasjon #4416
* Lagt til referansefelt til studie på vitnesbyrd #1974
* Sikkerhetsoppdatering av core, context, entitiy\_ref og eu\_cookies #4430
* Rydde i staging-scripts #4314


# Release 4.2 _2013-11-18_

Forberedende saker til migrasjon av området /utdanning, opprettinger etter forrige release, funksjonalitet i webdesk for innholdstypen "Tilknyttet innhold" og endring av logoer på forsiden uib.no.

* Bytter ut de to logoene på forsiden til uib.no (engelsk og norsk) med logo for grunnlovsjublieet #4373
* Artikkelinfo var ved en feil flyttet over hovedbildet på artikkel etter forrige release. Dette er nå flyttet ned på riktig plass. #4328
* Gjort mulig rss-feed for nyheter og hendelser fra ansattsidene #4310
* Lagt til områdetilhørighet for "Tilknyttet innhold" - vises nå også i webdesk og i søk fra webdesk for rolle 2 #4265 #3742 #3743
* Lagt til mer luft mellom kolonner som viser tilknyttet innhold for å hindre at lange titler overskriver neste kolonne #4043
* Regulert antall tegn som vises for tittel på emner for å unngå tekst utover tekstboks #3917
* Lagt til default-bilde i nyhetsarkiv når det ikke er bilde på saken #3362
* Lagt til mellomrom mellom tittel og dato i rss-feed #4246
* Diverse saker som forbereder migrasjon og presentasjon av området /utdanning #171 #1279 #4283 #4284 #4286 #4288

# Release 4.1 _2013-10-31_

Release gjør primært en rekke justeringer i layout på forsidene.

* Fjerner ubrukte field-groups #3914
* Gjør tittelen i vitnesbyrd-teaser til en link og sørger for at Les mer-lenken alltid kommer under teksten #3945 #4185
* Fikser innstilling som gjorde at tilknyttet innhold med titler på over 80 karakterer ikke virket som lenke #4032
* Fikser oppsett i fremhevet innhold-feltet på områdeforsiden, mht luft og rekkefølge på innhold lagt som kulepunktliste #4012 #4037
* Fiks for bug som ikke gjorde det mulig å hente eksisterende innhold fra fillagret #1448
* Fjerner lenke fra tredje brødsmulenivå #3791
* Gir luft rundt main media på områdeforsiden når main media er en video #4007
* Øker bredden på main media når det ikke er tekst eller sidebar på siden #4157
* Reorganiserer kolonnelayout på områdeforsiden #3930
* Fiks for sjekk av områdemeny satt til bare å sjekke ved migrering #3955

# Release 4 _2013-10-14_

Release tar seg primært av migrering av området Psykologisk fakultet til ny plattform. I tillegg gjøres noen små rettelser.

* Fiks for felt på område som dukket opp selv om det var tomt #3948
* Fiks for kulepunkter i faktaboks som forsvant i R3.2 #3973
* Styling på kalenderlenker på engelske og norske sider justert slik at de samsvarer #3642
* Fiks for å hindre at brødsmulestien viser begge stiene når en side ligger flere steder i menyen #3972
* Fiks for oversettelse av hendelses-typer i årsvisning på kalender #3974
* Forarbeid, testmigrasjon og opprydning foran endelig migrasjon i R4 ble gjort i sakene #3760 #3747 #3981 og #3763

# Release 3.2.1 _2013-10-10_

Faner ble ikke lenger presentert for artikler (regresjon i 3.2) #3950

# Release 3.2 _2013-10-09_

Release for løpende fix på diverse saker og moduloppdatering av Drupal, ny layout for tilknyttet innhold, reformatterer og rydder opp i template.php, og funksjonalitet for å gjøre folk oppmerksomme på cookies på nettstedet. I tillegg remigreres en forskergruppe som manglet etter migrasjonen av SV-fakultetet. Oppdateringen begynner også et arbeid med å restrukturere layout på area for å forbedre flyt og utseende.

* Ny layout på tilknyttet innhold organiserer opplistingen bedre og gir mulighet for å legge bilde til visningen, også for eksternt tilknyttet innhold #3829 #3848
* Justering av styling på "Foto" og "Opphavsrett" #3785
* Museumsbildet fjernes fra header i mobil visning #3774
* Reintroduksjon av tittel i teaser for vitnesbyrd på områdeforsiden, samt noe omorganisering av teksten i teaser #3827 #3277
* Tillegg for årsvisning i kalender samt reformattering av dato i månedsvisningen #3553 #1069
* Forberedelse for cookie-varsel for nettstedet (EU-krav) #3823
* Fiks for brødsmulestien #3840 #3860
* Fiks for ekstern forfatter i bylinefeltet på nyhetsartikler #3901
* Migrering av manglende forskergruppe (fg/demrett) etter migrasjon av SV-fakultetet #3811
* Reformatering av template.php #3812
* Oppgardering av moduler og fikser etter oppgraderingen #3753 #3918 #3911 #3908
* Opprydning av css og layout på område og fiks etter denne #3754 #3924 #3940 #3933
* Diverse tekniske saker #3858 #3818 #3762 #3740

# Release 3.1 _2013-09-18_

Release for løpende fix på diverse saker og moduloppdatering av Drupal.

* Ansattsidene har fått endret layout slik at den korresponderer med layout på øvrige sider på uib.no. Dette innebærer at lenker til videre lesing som tidligere stod som lenker til høyre, nå er flyttet ned under artikkelen. #3738
* Som en følge av dette måtte vi også justere på visning av lenker til eksternt innhold fra ansattsidene #3796
* Stylingjusteringer og bugfiks for visning på mobil #3786, #3792
* Justering i styling på publiserings-info mm #3722 #3583
* Oversettelse av kategoriene i event-filteret #2330
* Lagt til autocomplete på tilhørighet for artikler man søker opp som tilknyttet innhold #3649
* Fjernet mulighet til å legge til underpunkt på meny nivå 2 — siden dette ikke er et nivå brukt på nettstedet #3586
* Lagt til mulighet til å legge til lenker til Instagram og Google+ på områdeforsidene #3355 #3275
* Lagt til default "Nyhet" i kicker på /aktuelt-sidene, der kickerfeltet ikke er fyllt ut #3308
* Lagt til overskrift på ansattlistene på område #3167
* Core og moduloppdateringer av Drupal #3433
* Diverse tekniske saker #3746 #3740 #3730 #3729 #3709 #3591

# Release 3.0.1 _2013-09-12_

La inn reklame for Forskningsdagene på forsiden.  #3736

# Release 3.0 _2013-09-11_

Release migrerer SV-fakultetet til ny plattform og gjør dessuten en del opprettinger etter r2.2 (menysplit)

* Migrerer SV-fakultetet og sub-områder til ny plattform #3661 #3708
* Setter opp redirects for nyheter og hendelser i arkiv for sv-fakultetet #2454
* Fiks for migrasjon av lange filnavn eller filnavn med mellomrom #3617
* Rydder opp tomme menypunkt for sv-fakultetet etter menysplit #3536
* Fiks for brødsmulestien etter menysplit #3575
* Fiks for at vitnesbyrd skal kunne vises som relatert innhold #3717
* Fiks etter R2.2 som ga feilmelding på oversettelse av innhold #3705
* Fiks for å unngå visning av skjulte menypunkter på nivå tre (navigasjonssider) etter migrasjon #3707
* Justering av rettigheter i webdesk gir level 2 og 3-brukere redigeringstilgang bare til meny på egne områder #3643
* Lagt til rettigheter i webdesk fo level 2 og 3 til å legge til eksternt innhold
* Noen justeringer i forhold til feilmeldinger i migrasjon #3733, #3706



# Release 2.2.1 _2013-09-06_

Fikser problemet med at bare det første av de små bildene på artiklene var synlig. #3703


# Release 2.2 _2013-09-04_

Release onsdag 4. september splitter menyen til enkeltmenyer for hvert område og introduserer ny funksjonalitet for å legge artikler i meny og i relasjon til andre artikler.
Som en følge av dette har vi også justert rettighetene noe. I tillegg følger noen små justeringer på styling. Vi har også fjernet tilgang for level 2 brukere til å legge opp egen logo i tittelfeltet.
Vi har også tatt med et par saker som forbereder migrasjon av neste område (R3).

* Ny menystruktur og relaterte saker # 2587, #3549, #3619, #3585, #3567
* Justeringer og feilrettinger etter omorganiseringen av publiseringsinfo (#2537) #3356, #3454
* Feilretting i mobilmenyer #2318, #3572
* Rettet feil som gjorde at "Stilling ledig"-header viste selv om det ikke fantes ledige stillinger #3510
* Rettet bakgrunnsfarge i de store menyene på forsiden og /foransatte #3588
* Endret til level 1 rettighet for å få legge logo i tittelfeltet på siden
* Fiks for migrasjon av bildetekster fra w2 til w3 #3486
* Styling på /aktuelt og /news # 3535

# Release 2.1 _2013-08-19_

Release mandag 19. august gjør justeringer etter R.2, primært i frontend, både på desktop og mobil.

* Stylingjusteringer på forsiden og /aktuelt #3240, #3419, #3359, #3432
* Fjerne menyikon på sider uten meny i mobilvisning #3328
* Feil som gjorde at thumbnail-visning av video ikke vistes rettet opp #3416
* Casesensitivetet i e-postadresse fjernet #2586
* Diverse justeringer/rettinger på systemet #3437, #3453



# Release 2.0 _2013-08-13_

Release tirsdag 13. august. Migrasjon av forside uib.no og /aktuelt til w3.  Strengere tilganger til å redigere områder.

* Opprettet to nye områdetyper, "Frontpage" og "Newspage" #2989
* Global meny inkluderes i responsivt design. #2922
* Tilgangskontroll satt på forsiden og /aktuelt. #3055
* Noe omorganisering / redesign av publiseringsinfo i artikler. #2537
* Stikktittel er blitt flyttet over tittel på artikler. #1947
* Introbilde bruker full bredde hvis introtekst ikke er fylt ut. #2991
* Profilerte meldinger vises i høyremarg hvis område type er forside. #2994
* Følg oss (sosiale lenker) er flyttet til under slideshow. #2996
* Hjelpetekster på introbilde og profilerte meldinger er oppdatert. #3289
* Reorganisering av info på forsiden og oppsett for /aktuelt (øvrige saker).

# Release 1.7 _2013-06-24_

Release mandag 24. juni. Justeringer etter forrige release, noen tekniske ryddesaker.

* Forfatter blir lagt til automatisk i byline når en sak opprettes. - #2980
* Sosiale medier-ikoner på ansattsidene er fjernet - #3081
* Meny-header i høyre spalte på ansattsidene fjernes når siden ikke har lenker til undersider. - #3101
* Fikset feil i sykroniseringen med FS etter ITAs kontinuitetstesting 15. juni - #3163
* Fikset feil som fikk videoer til å forsvinne når vinduet ble smalt - #3221
* Oppgradering av moduler og andre tekniske saker - #3069, #2976, #3116, #933, #3047 #3031

# Release 1.6 _2013-06-10_

Release mandag 6. juni inneholdt både justeringer og feilrettinger. Dette ble gjort: 

* Print av sider fra uib.no har fått et godt og konsistent oppsett. - #2459
* Man kan nå liste opp administrativt og vitenskapelig ansatte ved enhetene separat. - #2706
* Det er lagt inn et ekstra felt for forfatter/byline. Dette fritekstfeltet kan brukes dersom forfatteren av saken ikke er har brukernavn ved UiB.- #2292
* Klikker man på et bilde i nyhetsarkiv-visningen, vil du komme inn på selve saken. -#2244
* Headingen "Ledige stillinger" viser ikke lenger på siden hvis det ikke faktisk er ledige stillinger å liste opp. -#2967
* "Opphavsrett" viser ikke under bilder på områdeforsiden. -#2786
* En oppdatering av styling i slideshow hindrer at lange titler i kalenderhendelser skriver over faktainformasjonen til høyre i bildet. -#2650
* Feil i sortering/rekkefølge på kalenderhendelser er rettet opp. -#2950
* Bug som fjernet innhold i media-browser er fikset. Dermed kan man igjen søke på bilder i biblioteket og se egne opplastinger i bildeeditoren. -#2949
* Noen justeringer i styling, hjelpetekster, samt en håndfull tekniske saker. - #3023, #3024 #2963, #2967, #2386, #2995

# Release 1.5 _2013-05-27_

Release mandag 27. mai inneholdt både justeringer og feilrettinger. Her er en oversikt over hva som ble gjort:

* Stikktittelen på arrangementer viser nå riktig arrangementstype, feks "Gjesteforelesning" eller "Seminar". #2429
* Bla-funksjon på plass i kalenderen på mobile plattformer. #2541
* Vi nærmer oss lanseringen av nye ansattsider på uib.no, og hovedmenyen for disse sidene trengte litt finpuss for å få riktig visning på mobile plattformer. Det har den fått nå! #2494
* I forrige release la vi til informasjon om copyright på bildene som legges ut på uib.no. Denne informasjonen trengte litt styling for ikke å få for stort fokus, spesielt på små bilder. Dette er nå rettet opp. #2903
* Diverse hjelpetekster i webdesken er justert. #2889
* I den innebygde webbrowseren på android-enheter har UiB-logoen på toppen av siden blitt strukket ut av proposjoner. Dette er nå rettet opp. #2511
* Lange navn på områder (f.eks. institutter eller forskergrupper) ble vist over to linjer og ga et uryddig inntrykk. Dette er nå justert, slik at lange områdenavn får en pen visning. #2886
* Kartvisningene på uib.no viser på riktig zoomet nivå. #2355
* For bedre sikkerhet for systemet har vi fjernet tilgang til menystruktur for level 2 og 3 i webdesk. #2948
* En håndfull saker gir interne forbedringer for økt stabilitet/ytelse. - #2464, #2619, #2906, #2907,#2917 og #2933.

# Release 1.4.2 _2013-05-15_

Logoen til [Grieg akademiet](http://www.uib.no/grieg) var blitt feilplassert i releasen fra 13. mai.

# Release 1.4.1 _2013-05-13_

Release mandag 13. mai inneholdt både nyutvikling, justeringer og feilrettinger. Her er en oversikt over hva som ble gjort:

* Nyheter og arrangementer vil nå automatisk flyte opp fra nivået innholdet er opprettet på til øverste nivå (fakultetsnivå). Når man oppretter en nyhet eller et arrangement, defineres denne flyten automatisk, men kan kan også overstyre den og definere den selv. Du kan lese mer om hvordan dette fungerer i brukerdokumentasjonen.
* Operative på nivå 2 og 3 kan lage en oversettelse knyttet til en artikkel i webdesken. Nå har disse også fått rettigheter til å knytte en allerede opprettet artikkel som oversettelse til en annen artikkel.
* Oprative på nivå 3 har fått rettigheter til å se revisjon av innhold
* URL lagt inn i "relevante lenker"-felt blir automatisk omgjort relative lenker, dersom de viser til interne sider på uib.no
* Bilder: copyright-feltet gjort synlig under bilder.
* Bilder: Label/kicker: FOTO lagt til under bildet, slik at hvis man fyller ut navn på fotograf, får det navnet en overskrift.
* Karusellen på områdeforsidene roterer nå automatisk.
* Arrangementsdata i karusell har fått ny styling.
* Visning av webdesk på iPad har fått en overhaling
* Feilmelding når "invalid users" fra sebra er synkronisert inn på liste over ansatte - rødt merke angir hvilke ansatte i listen det gjelder, og det er gitt mulighet til å fjerne dem fra listen før man lagrer området.
* Mye av innholdet på uib.no har ingen engesk oversettelse. Hvis du leser en norsk artikkel som ikke har engelsk oversettelse, og klikker på "English" oppe i høyre hjørne, får du nå rammeverket til engelsk nettsted (meny, kalender og nyheter), men den norske artikkelen blir stående med en tydelig varselmelding øverst: "The content of this article has not been translated."
* Brødsmulestien på de nye fagsider kom tilbake ved en feil i forrige release, og er nå fjernet igjen
* Feil i funksjon på søk i ansattkatalog, kom som som uventet følgefeil i forrige release. Denne feilen er nå rettet opp.
* Dato i kicker-feltet viser nå opprettet-dato, ikke sist oppdatert-dato.
* Feil i funksjon på søkefelt for mobile enheter er rettet opp.


# Release 1.4 _2013-05-07_

Denne releasen ble rullet tilbake etter at det ble oppdaget feil med hvordan aliasene ble generert.

# Release 1.3 _2013-04-22_

Generelt:

* Stikk-tittelfeltet har hatt noen bugs, disse blir rettet opp
* Filter på ansattelister på fag- og forskningsgruppesider blir fjernet
* E-postadresse i kolofonfeltet (bunn) blir klikkbart
* Visning av alle studieprogrammer/emner på fakultetsnivå på plass
* Bug som hindret ny sortering av saker i slideshow fikset
* Visning av kalendersaker i slideshow  - struktur fikset, design kommer i neste release
* Opprydning i kalendervisningen
* Nyhetssaker, kalendersaker og infosider får publisert-dato + sist-endretdato under byline. Blir stylet til neste release.
* Ser også ut til at vi får på plass en fiks som gjør at uansett hva slags intern lenke du limer inn i tekst i en sak, vil den bli rettet til en relativ lenke og dermed funke (rensker bort w3 og https-lenker
* Ser ut til at vi får på plass saken som fikser språktilhørighet for bildetekstene - vi må snakke om om dere ønsker at vi skal pushe en flytting til fra Alternativ tekst til Description (dette vil overskrive evt endringer gjort). Jeg kan forklare denne saken litt nærmere på tirsdag.
 
Spesifikt for Ansattsidene:

* Menyen på ansattesidene virker nå i responsiv design (små brett/mobil)
* Lenker videre-menyen på Ansattesidene er nå flyttet opp til høyre for teksten i artikkelen
 
samt en del tekniske saker som rydder og effektiviserer

# Release 1.2 _2013-04-12_

# Release 1.1 _2013-04-08_

# Release 1.0 _2013-03-21_

Denne kom litt brått på, men nå er vi live.
