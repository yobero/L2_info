/*
 * Octet.js
 * Auteur : Luc De Mey
 *
 */

 
function jVeuxMaFenetre() 
{
 if ( top.location.href != self.location.href) {
  top.location.href = self.location.href;
 }
}


//Calques
//~~~~~~~
VersionNavigateur = parseFloat(navigator.appVersion); 

var layers = (document.layers ? true : false);
var zIdx  = -1;
function montreCalque(k)
{
 if ( layers)  // Ancienne version de NN
  document.layers[k].visibility='show';
 else if ( navigator.appName == 'Netscape')  // Version récente de NN
  document.getElementById(k).style.visibility = 'visible';
 else // MS Internet Explorer
  document.all[k].style.visibility = 'visible';
}

function cacheCalque(k)
{
 if ( layers) // Ancienne version de NN
  document.layers[k].visibility = 'hide';
 else if ( navigator.appName == 'Netscape') // Version récente de NN
  document.getElementById(k).style.visibility = 'hidden';
 else
  document.all[k].style.visibility = 'hidden';
}

function CalqueNEstPas(k)
{
 // Rendre True si le calque k est caché
 if ( layers) // Ancienne version de NN
  return (document.layers[k].visibility=='hide')    
 else if ( navigator.appName=='Netscape') // Version récente de NN
  return (document.getElementById(k).style.visibility=='hidden')
 else
  return (document.all[k].style.visibility=='hidden')
}

var cadres=0;
var i=0;

// Liste des chapitres "Initiation à l'informatique"

InitInfo = new Array(
 "sommaire.html","Sommaire",
 "Windows.html", "Le syst&egrave;me d'exploitation Windows",
 "DemarragePC.html", "D&eacute;marrage du PC",
 "Bureau.html","Pr&eacute;sentation du poste de travail",
 "Fenetres.html","Les fen&ccedil;tres",
 "MenuDemarrer.html","Le menu d&eacute;marrer",
 "Clavier.html","Le clavier",
 "Souris.html","La souris",
 "PersonnaliserMenuDemarrer.html","Personnaliser le menu D&eacute;marrer",
 "Fichiers.html","Les fichiers et l'explorateur Windows",
 "Extensions.html","Les extensions de noms de fichiers",
 "Rechercher.html","Rechercher un fichier ou un dossier",
 "PzBureauVista.html","Exercice &agrave; propos de bureau de Vista",
 "PzElementsFenetre.html","Exercice : Les &eacute;l&eacute;ments d'une fen&ccedil;tre",
 "PzExtensions.html","Exercice : les extensions des noms des fichiers",
 "MajXP.html","Mise &agrave; jour de Windows XP",
 "Antivir.html","T&eacute;l&eacute;charger et installer un antivirus",
 "sommaire.html","Retour au sommaire"
 );

Excel = new Array(
 "sommaire.html","Sommaire",
 "Tableur.html","Qu'est ce qu'un tableur ?",
 "Feuilles.html","Gestion des feuilles",
 "LignesEtColonnes.html","Gestion des lignes et des colonnes",
 "Formules.html","Formules",
 "References.html","Références",
 "FonctionsPredefinies.html","Fonctions prédéfinies",
 "FonctionsLogiques.html","Fonctions logiques",
 "Graphiques.html","Graphiques",
 "RechercheV.html","RechercheV",
 "FonctionsFinancieres.html","Fonctions financières",
 "Listes.html","Tables ou listes de données",
 "Listes_Tri.html","Trier une liste de données",
 "Listes_Filtre.html","Filtrer une liste de données",
 "sommaire.html","Retour au sommaire"
 );

// Liste des chapitres "Technologie des ordinateurs"

Techno = new Array(
 "sommaire.html","Sommaire",
 "Historique.html","Les origines de l'informatique",
 "Historique2.html","G&eacute;n&eacute;rations d'ordinateurs",
 "Informatique.html","D&eacute;finitions : informatique, information",
 "NumeriqueVsAnalogique.html","Num&eacute;rique vs Analogique",
 "Numeration.html","Num&eacute;ration binaire et hexad&eacute;dimale",
 "FctLogiques.html","Les fonctions logiques",
 "PortesLogiques.html","Les portes logiques",
 "ArchMat.html","Architecture mat&eacute;rielle",
 "CPU.html","Le processeur",
 "Memoire.html","La m&eacute;moire",
 "DisqueDur.html", "Le disque dur",
 "LiaisonsSP.html", "Liaisons s&eacute;rie et parall&egrave;le",
 "Interrupt.html","Les interruptions",
 "sommaire.html","Retour au sommaire"
 );
// Liste des chapitres "Hardware et Maintenance matérielle"

Hard = new Array(
 "sommaire.html","Sommaire",
 "Electro.html","Notions d'&eacute;lectronique",
 "Effets_I.html","Les effets du courant",
 "ACDC.html","Courant alternatif",
 "Mesures.html","Mesures &eacute;lectriques",
 "Capa.html","Condensateurs",
 "Self.html","Bobines, selfs ou inductances",
 "Transfo.html","Les transformateurs",
 "SemiConducteur.html","Les semi-conducteurs",
 "CircuitsImprimes_.html","Circuits imprim&eacute;s",
 "CircuitsIntegres_.html","Circuits int&eacute;gr&eacute;s",
 "Composition.html","Composition d\'un PC",
 "Boitier.html","Le bo&icirc;tier",
 // "Cablage.html","Câblage et connectique",
 "Alimentation.html","L'alimentation",
 "Onduleur.html","Les onduleurs",
 "CarteMere.html","La carte m&egrave;re",
 "Processeur.html","Le processeur",
 "Peripherique.html","Les p&eacute;riph&eacute;riques",
 "Bus.html","Le bus",
 "Chipset.html","Le chipset",
 "Memoire.html","Les m&eacute;moires",
 "MemTest.html","Test et diagnostic de la m&eacute;moire",
 "Disque.html","Les disques durs",
 "Raid.html","Le RAID",
 // "CarteExtension.html","Les cartes d'extension",
 "CarteGraphique.html","Les cartes graphiques",
 "Couleurs_.html","Lumi&egrave;re et couleurs",
 "Ecran.html","Les &eacute;crans",
 "Imprimante.html","Les imprimantes",
 // "Scanner.html","Les scanners",
 // "Modem.html","Les modems",
 // "Webcam.html","Les webcams",
 "AssemblagePC.html","Assemblage d'un PC",
 "TestPC.html","Tests du PC",
 "Depannage_.html","D&eacute;pannage informatique",
 "BIOS.html","Le BIOS",
 "Setup.html","Le setup du Bios",
 "sommaire.html","Retour au sommaire"
 );




// Liste des chapitres "Architecture et Système d'exploitation"

OS = new Array(
 "sommaire.html","Sommaire",
 "StructureEnCouches.html","Structure en couches des syst&egrave;mes informatiques",
 "SysExpl.html","Qu'est ce qu'un syst&egrave;me d'exploitation ?",
 "Processus.html","La gestion des processus",
 "ProcessCom.html","Les communications inter-processus",
 "GestMem.html","La gestion de la m&eacute;moire",
 "FileSys.html","La syst&egrave;me de fichiers",
 "CmdDos.html","Le mode invite de commande",
 "Redirection.html","Les entr&eacute;es/sorties vues par MSDOS",
 "FichierCmd.html","Les fichiers de commandes",
 "Ex_Bat.html","Exemples de fichiers .bat",
 "Robocopy.html","ROBOCOPY",
 "MemDos.html","La m&eacute;moire sous DOS",
 "Boot.html","La proc&eacute;dure d'amor&ccedil;age d'un PC",
 "Comptes_2000.html","Groupes et utilisateurs locaux avec Windows 2000 Pro",
 "Comptes_XP.html","Groupes et utilisateurs locaux avec Windows XP",
 "Registry.html","La base de registre de Windows",
 "Debug.html","Le programme DEBUG",
 "Ubuntu_Init.html","Installation et prise en main d'UBUNTU",
 "sommaire.html","Retour au sommaire"
 );

// Liste des chapitres "Reseaux"

Reseaux = new Array(
 "sommaire.html","Sommaire",
 "Intro.html","Les r&eacute;seaux - Introduction",
 "Classif.html","Classification des r&eacute;seaux selon leur &eacute;tendue",
 "Espece.html","R&eacute;seaux d'homologues ou &agrave; serveur d&eacute;di&eacute;",
 "Essentiel.html","Que faut-il pour int&eacute;grer un PC dans un r&eacute;seau local ?",
 "Topologie.html","Topologie des r&eacute;seaux locaux",
 "Methode.html","Les m&eacute;thodes d'acc&egrave;s",
 "Cablage.html","Câblage des r&eacute;seaux locaux",
 "AppareilsReseau.html","Les appareils r&eacute;seau",
 "ModeleOSI.html","Le mod&egrave;le de r&eacute;f&eacute;rence OSI",
 "Architecture_TCP-IP.html","L'architecture TCP/IP",
 "TCPIP.html","L'adressage IP",
 "Outils.html","Les outils de diagnostic",
 "WiFi.html","Le WiFi",
 "sommaire.html","Retour au sommaire"
 );

// Liste des chapitres "Internet"

Internet = new Array(
 "sommaire.html", "Sommaire",
 "Firefox.html", "Pr&eacute;sentation du navigateur Firefox",
 "RechercheWeb.html", "Recherches sur la toile - Moteurs de recherche & annuaires",
 "Courriel.html", "Le courrier &eacute;lectronique",
 "OutlookExpress.html", "Cr&eacute;ation d'un compte de messagerie sur Outlook Express",
 "Gmail.html", "Courrier (webmail) avec Gmail",
 "BaBA_Html.html", "Le B.A-BA du langage HTML",
 "Html5.html", "Premiers &eacute;l&eacute;ments de html 5",
 "Styles.html", "Les feuilles de style",
 "sommaire.html", "Retour au sommaire"
 );

// Liste des chapitres "Programmation"

Programmation = new Array(
 "sommaire.html","Sommaire",
 "AvantPropos.html","Avant propos",
 "ElaboProg.html","Elaboration des programmes",
 "TstBcc32V55.html","Test du compilateur C++ version 5.5 & test du Turbo debuger de Borland",
 "IntroASM.html","Introduction &agrave; l'assembleur",
 "sommaire.html","Retour au sommaire"
 );


// Liste des chapitres "Math Info"

MathInfo = new Array(
 "sommaire.html","Sommaire",
 "Intro.html","Avant-propos",
 "Bases_de_Numeration.html","Num&eacute;ration et bases de num&eacute;ration",
 "Numeration_de_position.html","Num&eacute;ration de position",
 "Conv2Dec.html","Calcul de la valeur d'un nombre quelle que soit sa base",
 "NumerBin.html","Num&eacute;ration binaire",
 "PoidsDesBits.html","Exercice : Peser la valeur d'un nombre en binaire",
 "NumerHex.html","Num&eacute;ration hexad&eacute;cimale",
 "NbrCodes.html","Nombres de codes possibles avec N chiffres",
 "Puiss2.html","Puissances de 2",
 "ConvBaseB.html","Changement de base : D&eacute;cimal -> base quelconque",
 "NbrSignes.html","Nombres sign&eacute;s",
 "AddSubByte.html","Addition et soustraction de deux octets",
 "CalculettePapier.html","Simulation des calculs hexad&eacute;cimaux avec une calculette en papier",
 "CalculsBinaires.html","Calculs binaires tels qu'ils sont faits dans le CPU entre 2 registres 8 bits",
 "FctLogiques1.html","Logique Bool&eacute;enne",
 "FctLogiques2.html","Combinaisons de fonctions logiques",
 "PortesLogiques.html","Portes logiques",
 "Comparateur.html","Circuits logiques - Comparateur",
 "Additionneur.html","Circuits logiques - Additionneur",
 "sommaire.html","Retour au sommaire"
 );

function Numero(nom) {
  //alert("nom = " + nom + " = " + eval(nom));
//  document.write('&nbsp; &nbsp; &nbsp; &nbsp; '+eval(nom) + '&nbsp; ');
  document.write('<div style="text-align: right;  ">'+eval(nom) + '</div>');
}

function Ch(nom) {
  //alert("nom = " + nom + " = " + eval(nom));
  document.write( '<p style=" margin:0px 0ex 0px 0px;" align="right">' + eval(nom) + '&nbsp; </p>');
}

function hrefCourstechinfo()
{
 /*
      <a href="http://www.courstechinfo.be">
          <img id="Octet" src="../Img/CoursTI0.png" width="100" height="50" border="no" align="left" alt="courstechinfo"
          onmouseover="document.images.Octet.src='../Img/CoursTI1.png';" 
          onmouseout="document.images.Octet.src='../Img/CoursTI0.png';" 
	title="Retour à la page d'accueil du site" hspace="3" vspace="2" /> 
      </a>
    */
    document.write('<a href=\"http://www.courstechinfo.be\"> <img id=\"Octet\" src=\"../Img/CoursTI0.gif\" width=\"100\" height=\"50\" border=\"no\" align=\"left\" alt=\"www.courstechinfo.be\"');
	document.write('onmouseover="document.images.Octet.src=\'../Img/CoursTI1.gif\';" onmouseout="document.images.Octet.src=\'../Img/CoursTI0.gif\';" title="Retour &agrave; la page d\'accueil du site" hspace="3" vspace="2" /> </a>');
}

function barreMenuDuSite(path)
{
 var adressesLiens = new Array( 
  "/InitInfo/sommaire.html","Init Info","Initiation &agrave; l'informatique pour grands d&eacute;butants",
  "/Techno/sommaire.html","Techno","Introduction &agrave; la technologie des ordinateurs",
  "/Hard/sommaire.html","Hardware","Hardware & Maintenance mat&eacute;rielle",
  "/OS/sommaire.html","OS","Syst&egrave;me d'exploitation",
  "/Reseaux/sommaire.html","R&eacute;seaux","Initiation aux r&eacute;seaux",
  "/Internet/sommaire.html","Internet","Internet / Intranet",
  "/Programmation/sommaire.html","Programmation", "Notions de programmation",
  "/MathInfo/sommaire.html","Math Info","Math&eacute;matiques appliqu&eacute;es &agrave; l'informatique",
  "/Excel/sommaire.html","Tableur","Initiation tableur"
  );

 var str="";
 var index="";

 var Repertoire = EmplacementDuSite(document.URL);

 for ( var i=0; 3*i<adressesLiens.length-3; i++) {
  str += '&nbsp;<a href="' +path + adressesLiens[3*i] + index + '"'
   +'title="' + adressesLiens[(3*i)+2] + '"'
   +'target="_top">' 
   +'<u>'+adressesLiens[3*i+1]+'</u>'
   + '</a>&nbsp; &nbsp;';
 }
 // Dernier href de la ligne vers Liens.html ( ne jamais ajouter index.html a cette href)
 str += '&nbsp;<a href="' +path + adressesLiens[3*i] + '"'
  +'title="' + adressesLiens[(3*i)+2] + '"'
  +'target="_top">' 
  +'<u>'+adressesLiens[3*i+1]+'</u>'
  + '</a>';
 
 document.writeln('<div style="position:relative; top:20px; left:0px; width:780px; text-align:center;">'+str+'</div>');
}

function ValidationW3C()
{
 document.write('<a href="http://validator.w3.org/check?uri=referer"><img style="border:0; width:88px; height:31px;" hspace="10px" src="../Img/valid-xhtml10-blue.png" alt="XHTML	1.0	validé!" /> </a>');
 document.write('<a href="http://jigsaw.w3.org/css-validator/check/referer"><img style="border:0; width:88px; height:31px;" src="../Img/vcss-blue.png" alt="CSS validé!" /></a> &nbsp;'); 
}
function AnalysesXiTi(page)
{
 document.write('<a href="http://www.xiti.com/xiti.asp?s=254710" title="WebAnalytics" target="_blank" >');
 Xt_param = 's=254710&p='+page;
 try {Xt_r = top.document.referrer;}
 catch(e) {Xt_r = document.referrer; }
 Xt_h = new Date();
 Xt_i = '<img width="80" height="15" border="0" ';
 Xt_i += 'src="http://logv31.xiti.com/bcg.xiti?'+Xt_param;
 Xt_i += '&hl='+Xt_h.getHours()+'x'+Xt_h.getMinutes()+'x'+Xt_h.getSeconds();
 if (parseFloat(navigator.appVersion)>=4)
 {Xt_s=screen;Xt_i+='&r='+Xt_s.width+'x'+Xt_s.height+'x'+Xt_s.pixelDepth+'x'+Xt_s.colorDepth;}
 document.write(Xt_i+'&ref='+Xt_r.replace(/[<>"]/g, '').replace(/&/g, '$')+'"></a>');
}

function barreMenu(path)
{
 hrefCourstechinfo();
 barreMenuDuSite(path);
}


function NavigCours(cours,ch,urlPrecedente, fichierActuel, fichierPrecedent)
{ 
 // Affiche le chemin vers la page et deux flèches pour naviguer dans le chapitre : 
 //  à droite = le lien vers le chapitre suivant
 //  à gauche = le lien vers le chapitre précédent
 //                   ou vers l'url précédente si celle ci est spécifiée 
 var adr_g,adr_d,titre_g,titre_d;
 
 // Les paramètres urlPrecedente, fichierPrecedent et fichierActuel sont facultatifs
 // Ils ne doivent être définis que pour les pages de type "arrières petits enfants"
 // qui ne suivent pas l'ordre des pages de cours

 //alert(" NavigCours: cours = "+cours);
 tbl = eval(cours);
 // alert(" NavigCours: tbl = "+ tbl);

 adr_g = tbl[(ch-1)*2];
 titre_g = tbl[(ch-1)*2+1];
 adr_d = tbl[(ch+1)*2];
 titre_d = tbl[(ch+1)*2+1];

 document.write("<table width=\"100%\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\" style=\"font-family:'Comic Sans MS'; color:#333; \"><tr><td bgcolor=\"#E0E8F8\" width=\"100%\" height=\"14\">");
 // alert("ch = "+ch+ " ; tbl.length = "+tbl.length);
 document.write('<img align="right" src="../Img/Blanc.gif" width="16" height="16" border="no" title="" alt="" >');
 if (ch != -1) {
  if ( (ch+1)*2 < tbl.length)
  document.write('<a href="'+ adr_d +'"><img align="right" src="../Img/Drt.gif" width="16" height="16" border="no" title="'+ titre_d +'"></a>');
  document.write('<img align="right" src="../Img/Blanc.gif" width="16" height="16" border="no" title="">');
  if ( ch > 0)
   document.write('<a href="'+ adr_g +'"><img align="right" src="../Img/Gch.gif" width="16" height="16" border="no" title="'+ titre_g +'"></a>');
  }
  else if ( urlPrecedente != undefined) {
   document.write('<img align="right" src="../Img/Blanc.gif" width="16" height="16" border="no" title="">');
   document.write('<a href="'+ urlPrecedente +'"><img align="right" src="../Img/Back.gif" width="16" height="16" border="no" title="retour &agrave; la page prfc&eacute;dente"></a>');
  }
  document.write("&nbsp; &nbsp; <a href=\"../index.html\" title=\"Page d'accueil du site\" style=\"font-family:'Comic Sans MS';\">CoursTechInfo</a>");

  if (cours=="InitInfo") {  
   if (ch == 0)
    document.write(" &gt; Initiation &agrave; l\'informatique");
   else
    document.write(" &gt; <a href=\"sommaire.html\" title=\"Notes de cours : \'Initiation &agrave; l'informatique\'\"> Initiation &agrave; l\'informatique</a>");
  }
  else if (cours=="Techno") {
   if (ch == 0)
    document.write(" &gt; <span title=\"Introduction &agrave; la technologie des ordinateurs\" style=\"cursor:default\">Technologie des ordinateurs</span>");
   else
    document.write(" &gt; <a href=\"sommaire.html\" title=\"Introduction &agrave; la technologie des ordinateurs\"> Technologie des ordinateurs </a>");
  }
  else if (cours=="Hard") {
   if (ch == 0)
    document.write(" &gt; <span title=\"Hardware \& Maintenance mat&eacute;rielle\" style=\"cursor:default\">Hardware</span>");
   else
    document.write(" &gt; <a href=\"sommaire.html\" title=\"Hardware \& Maintenance mat&eacute;rielle\"> Hardware</a>");
  }
  else if (cours=="OS") {  
	if (ch == 0)
      document.write(" &gt;  <span title=\"OS = Operating system\" style=\"cursor:default\">Syst&egrave;me d\'exploitation</span>");
	else
	  document.write(" &gt; <a href=\"sommaire.html\" title=\"OS = Operating system\"> Syst&egrave;me d\'exploitation </a>");
  }
  else if (cours=="Reseaux") {
	if (ch == 0)
      document.write(" &gt; <span title=\"Notes sur les r&eacute;seaux\" style=\"cursor:default\">R&eacute;seaux</span>");
	else
	  document.write(" &gt; <a href=\"sommaire.html\" title=\"Notes sur les r&eacute;seaux\"> R&eacute;seaux</a>");
  }
  else if (cours=="Internet") {
	if (ch == 0)
      document.write(" &gt; <span title=\"Notes de cours : \'Internet-Intranet\'\" style=\"cursor:default\">Internet</span>");
	else
	  document.write(" &gt; <a href=\"sommaire.html\" title=\"Notes de cours : \'Internet-Intranet\'\"> Internet</a>");
  }
  else if (cours=="Programmation") {
	if (ch == 0)
      document.write(" &gt; <span title=\"Notions de programmation\" style=\"cursor:default\">Programmation</span>");
	else
    document.write(" &gt; <a href=\"sommaire.html\" title=\"Notions de programmation\"> Programmation</a>");
  }
  else if (cours=="MathInfo") {
	if (ch == 0)
      document.write(" &gt; <span title=\"Notes du cours de math&eacute;matiques appliqu&eacute;es &agrave; l'informatique\'\" style=\"cursor:default\">Math Info</span>");
	else
	  document.write(" &gt; <a href=\"sommaire.html\" title=\"Notes du cours de math&eacute;matiques appliqu&eacute;es &agrave; l'informatique\'\"> Math Info</a>");
  }


  if (fichierActuel != undefined) {
		if ( (urlPrecedente != undefined) && (fichierPrecedent != undefined) ) {
			document.write(" &gt; <a href=javascript:void() title=\"Vous &ccedil;tes ici\">");
  		document.write('<a href="'+ urlPrecedente +'"> '+ fichierPrecedent +'</a>');
  		document.write("</a>");
		}
  	// / document.write(" &gt; <a href=javascript:void() title=\"Vous êtes ici\">");
   	document.write(" &gt;  <span style=\"cursor:default\">");
  	document.write( fichierActuel);
  	document.write("</span>");
  	// /document.write("</a>");
	}
	  
  if (ch > 0) 	// -1 = indéfini     0 = sommaire
  {
   	// / document.write(" &gt; <a href=javascript:void() title=\"Vous êtes ici\">");
   	document.write(" &gt;  <span style=\"cursor:default\">");
  	document.write( tbl[(ch)*2+1]);
  	document.write("</span>");
  	// / document.write("</a>");
	}

  document.write("</td></tr></table> ");
}

function BoutonHaut()
{
  // alert(parseFloat(navigator.appVersion));
  if (parseFloat(navigator.appVersion)>=4)
  {
    document.write("<div style=\" position:fixed; top:20px; left:844px;  z-index: 10;  \">	<a href=\"#haut\">");
//    document.write("<div style=\" position:fixed; bottom:10px; left:864px; \">	<a href=\"#haut\">");
    document.write("<img src=\"../Img/TopOff.png\" title=\"Haut de la page\" alt=\"\" style=\"width: 16px; height:14px; border:0px;\"");
    document.write("onmouseover=\"this.src=\'../Img/TopOn.png\';\"  onmouseout=\"this.src=\'../Img/TopOff.png\';\" /> </a> </div>");
  }
}

function BoutonBas()
{ 
 if (parseFloat(navigator.appVersion)>=4)
 {
   document.write("<div style=\" position:fixed; bottom:10px; left:844px; z-index: 10;  \">	<a href=\"#bas\">");
   document.write("<img src=\"../Img/BottomOff.png\" title=\"Bas de la page\" alt=\"\" style=\"width: 16px; height:14px; border:0px; \"");
   document.write("onmouseover=\"this.src=\'../Img/BottomOn.png\';\"  onmouseout=\"this.src=\'../Img/BottomOff.png\';\" /> </a> </div>");
 }
}

function NomChap(tbl,num)
{ // Affiche le nom d'un chapitre en fonction du cours et du n° du chapitre
  document.write(tbl[(num)*2+1]);
}


function NumChap(adresse)
{ // Recherche du cours et du numéro d'un chapitre en fonction de son adresse et retourne cette valeur
  var i, fin, p, chemin, cours, page, tbl;
  // alert(" NumChap: adresse = "+ adresse);
  p = adresse.lastIndexOf('\/');
  chemin = adresse.slice(0,p);
  // alert(" NumChap: chemin = "+ chemin);
  if ( chemin == "file:/")  {       // Car Internet Explorer utilise des '\' comme séparateurs !
    p = adresse.lastIndexOf('\\');
    chemin = adresse.slice(0,p);
    page = adresse.slice(p+1);
    p = page.lastIndexOf('#');      // Si l'adresse est de la forme page.html#name
    // alert("NumChap IE: p = "+ p);
    if ( p != -1)                   // S'il y a un signe #
      page = page.slice(0,p);       //   ne conserver que ce qui précède le signe #
    // alert("NumChap IE: page = "+ page);
    p = chemin.lastIndexOf('\\');
  }
  else {                            // Avec un bon navigateur
    page = adresse.slice(p+1);
    p = page.lastIndexOf('#');      // Si l'adresse est de la forme page.html#name
    // alert("NumChap OK: p = "+ p);
    if ( p != -1)                   // S'il y a un signe #
      page = page.slice(0,p);       //   ne conserver que ce qui précède le signe #
    // alert("NumChap OK: page = "+ page);
    p = chemin.lastIndexOf('\/');
  }
  cours = chemin.slice(p+1);
  // alert(" NumChap: cours = "+ cours);
  tbl = eval(cours);
  fin = tbl.length -1;
  for ( i = 0; i < fin; i++) {
    if ( tbl[i*2] == page) {
      return i;                     // Rend le numéro du chapitre
    }
  }
  return -1;  // Non trouvé
}


function NumPage(cours,page)
{
  // Affiche le n° d'une page en fonction de son nom
  var tbl, fin;
  // alert(" NumPage(): cours = " +cours);
  tbl = eval(cours);
  // alert(" NumPage(): tbl = " +tbl);
  fin = tbl.length -1;
  // alert("NumPage(): fin = " +fin);
  for ( i = 0; i < fin; i++)  {
    // alert(" NumPage(): i, tbl[i*2], page = "+i+", "+tbl[i*2]+", "+page);
    if ( tbl[i*2] == page)  {
      document.write( i);
      return;
    }
  }
}

function NomDuCours(adresse)
{
  var p,chemin,cours;
  // alert("NomDuCours: adresse = "+ adresse);
  p = adresse.lastIndexOf('\/');
  chemin = adresse.slice(0,p);
  // alert("NomDuCours: chemin = :"+chemin);
  if ( chemin == "file:/")  {         // Ce qui arrive avec Internet Explorer !
    p = adresse.lastIndexOf('\\');    // Car Internet Explorer utilise des '\' comme séparateurs !
    chemin = adresse.slice(0,p);
    p = chemin.lastIndexOf('\\');
  }
  else {
    p = chemin.lastIndexOf('\/');
  }
  // alert( "NomDuCours: position de l'avant dernier slash = "+p); 
  cours = chemin.slice(p+1);
  // alert("NomDuCours: Cours = "+cours);
  return cours;
}

function EmplacementDuSite(adresse)
{
  // Recherche de l'emplacement des pages ex www.courstechinfo.be ou ..../octet
  var p,q,chemin,cours,emplacement,repertoire;
  // alert("EDP: adresse = "+ adresse);
  p = adresse.lastIndexOf('\/');
  chemin = adresse.slice(0,p);
  // alert("EDP: chemin = :"+chemin);
  if ( chemin == "file:/")  {         // Ce qui arrive avec Internet Explorer !
    p = adresse.lastIndexOf('\\');    // Car Internet Explorer utilise des '\' comme séparateurs !
    chemin = adresse.slice(0,p);
    p = chemin.lastIndexOf('\\');
    emplacement = chemin.slice(0,p);
    q = emplacement.lastIndexOf('\\');
  }
  else {
    p = chemin.lastIndexOf('\/');
    emplacement = chemin.slice(0,p);
    q = emplacement.lastIndexOf('\/');
  }
  repertoire = emplacement.slice(q+1);
  // alert("EDP: emplacement = "+emplacement+" repertoire = "+repertoire);
  return repertoire;
}


function favico()
{
  document.write('<link rel="SHORTCUT ICON" type="images/x-icon" href="../Img/octet'+Chapitre+'.ico" />');
}

// Ouverture systématique des liens externes dans une nouvelle fenêtre
// D'après http://www.alsacreations.com/tuto/lire/556-liens-externes-nouvelle-fenetre.html
function open_ext_link()
{
  var liens = document.getElementsByTagName('a');
  // On récupère tous les liens du document dans une variable liens.
  // Une boucle qui parcourt le tableau (array) liens du début à la fin
  for (var i = 0 ; i < liens.length ; ++i)  {
    // Si les liens ont un nom de class égal à lien_ext, alors on agit
    if (liens[i].className == 'externe')  {
      // liens[i].title = 'Lien externe';
      // Au clic de la souris.
      liens[i].onclick = function()  {
        // On ouvre une nouvelle page ayant pour URL
        // l'attribut href du lien cliqué et on inhibe le lien réel
        window.open(this.href);
        return false;
      };
    }
  }
}
// Au chargement de la page, on appelle la fonction.
window.onload = open_ext_link;




