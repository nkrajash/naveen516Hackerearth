/* All Tracks -->  Basic Programming --> Input/Output --> Basics of Input/Output --> Problem -->
Anagrams
Tag(s): Very-Easy
Given two strings, a and b , that may or may not be of the same length, determine the minimum number of character deletions required to make a and b anagrams. 
Any characters can be deleted from either of the strings.

Input :
test cases,t
two strings a and b, for each test case
Output:
Desired O/p
Constraints :
string lengths<=10000

Note :
Anagram of a word is formed by rearranging the letters of the word.
For e.g. -> For the word RAM - MAR,ARM,AMR,RMA etc. are few anagrams.

SAMPLE INPUT 
1
cde
abc
SAMPLE OUTPUT 
4

//My C Solution:
#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

int main(){
    char a[MAX],b[MAX];
    int *Freq,t,j,minana;
    scanf("%d",&t);
    while(t--){
        Freq = (int *)calloc(26,sizeof(int));
        minana=0;
        scanf("%s",a);
        scanf("%s",b);
        for(j = 0;a[j]!='\0';++j)
            Freq[(a[j]-'a')]++;
        for(j = 0;b[j]!='\0';++j)
            Freq[(b[j]-'a')]--;

        for (j=0; j<26; j++)
            minana+= abs(Freq[j]);
        printf("%d\n",minana);
        free(Freq);
    }
    return 0;
}

*/

/*I/O:
In #1:
10
tttttttttttttttttttttttttttttttttttttsssssssssssssssss
sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa
bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
gsadasfdashdasdkjgadhjdyjhasfdasgd
ajdfaghfsdasgdfagsdhgasdfasfdahd
ahjjjjjjjjjjjjjjjjjjjjjjsdgajfhsdhafshdfasjdsahfdasd
aksuhdgyhjagsdjhasdkjasldashdlashdjas
aiustdiagsdiiiiiiiiiyasdhkagdyafdfasdfausda
ajkgdiuagdiyafdiayfdkafdkadfad
aaskjdgiuagdalidiaudghasugd
ausigtduasgdaksdgasldgbslgdisudgs
ajhdasnhccniuadgasfdgsajasdvasdvasdas
alfdlhasdlasgdjasgdlasdgiyasfdsadasd
akusdiluasdasvdihasidasjldsadas
asgdiuasgdiuavdlavdasdvsdlvsulyd
jhghdjhsgfjhsvfjdsvfjhsvfjvsdfsd
slfgyedgflsdgfilydsgfipgdsipfgdsfgd
sduifiusdgfiulsdgfigsdilfuseteygyewrfwurw
lwuigrywfdlfsdfisegfsdgfs
Out #1:
107
104
10
33
21
16
19
17
35
16
In #2:
1
qeltuiosytrabycsnvdourrbvarooaqhgdaaoovmkonlnrdcpirjckkxkbnydffklhmzwhngyctnuzpjjislsfleiyfmgkwrskqqufysirfeqwnchhnbmygvzlhfxfwrrohltfddzkhrhutqejrqhxnikuniblztzjevqkyruijdcetinnzxkmfvjvfmgghirodiydbulmaqrvygizfvolsxizlqftaxjfhhjidwvfmodnwnocicpcbxbnpjiqirvpagzfdwlrmqgjdvloxaqzxuoodwelnccnidsnaffmvnvzigpigfhfbxuetaricvxlzrybxfnutlvdrklasuhtrdaketsgprtqjurizecurayjklleguyxyaketemkwgaharpbytwptwaghnkpiknikzmgdaszgtgimxkmriekggqpubfenuoytcgwcyyjtgtiefuvpahvhylbbshqmvofxwbbxzmqigamlvhbxqyeqlhtdokplawixymuzymhenvskethvtmlftfiipatpweowqkwoxfvkdnuhidcbpqglvrtmrodpuummekdbrynuljcvngwewfptwkhpblevhqilcnpulcoyoqtdxrhvwxpuhyjklqgsiqeldvfqztonmjqlaygzxxtgwfrhvzadpgoudtmcpaqblimlgumfsgmqlfzieblvjcrmxdpmffpqnddwyqdswpkjwjralexugojetysyfiquluslmwdknntkzmmmqkixardwpvwwfnrrjjcvfiftxadymrkcbtbemgcceyyjlrcubfrgpwboygnkyxpzssffzhjdgjotbrqcyhkngmdesqpqqgskyzpzjacpkrkliapikbvqnywirlahtursujrdjwuvpeizhxhrzejocfyvtzemvygrhyuswqqlxykeytxzxgnbloxepbtkzzcixybvrtgorsupnrqkzgmmujrjmmvmlzulyxgpqpfkjzbxsshtyvfsgydtkahwadhadnpvewfovhlpzuizsntamyvyycuyibylrpgvlolivyxwthvnxqnlojjmnenvhniadpyqfjbaiyydivqflfqzqznefabpokptbplgzmijngmvbeaolsnctagbdhqtthmuxzaymkhzqvwtbwhmquojxwmcgcvzkjwjiyhujovzlrtmpaafxrrwndyvitvuctdmrkhaaeclwxzlzztwqmserqbzlyvnryajkjlknpxlmwxmwskmedsvvuxhsswktyvdjiqxynikmhyizjwfordllasfurrnporbxhyvwihisisttpzhgestenaygsoxgfyfoyckjmtbulwncvwkzqfffgglaulibjopiqztcuuyiqnkojvpaaxfidtizeranfpxxqsclmatfofvzckzfjhnmaylgplvwcvttnxgcabjqieplqrsayhmafaiundssyololtqlwzbedtrvkjvktkmymuvzznrabeonzeavdecixtdjfbtynhyzdtachuckaszawaxbezldtrmashyhqwitsixzeclfulfrlcurcgwxxkxrrxajvicpqzqvbcawnhpallrnrpmqzljqkjzirdxkeohgqjefsvfdgytanfsmteednfnhiltmbcutnayfvdieddgqjycecgjsnxbvkwjlyegleescjagmeoepmgvroelbdmynkhainivumnwxpeltspkgxfxnmkqpwofgyhqlqnfeadcqhplbfykefjsruihszozxvrilfqshtuzdjlgqlqxqapiwzroyhnxchgqmyivtevwpifitvfjxwttvmiwtxtyeboszyotclrrtwzmsgxrctlyfvubspzzrntqnjjpubinxkbrqzltsytztpanezovoimbrxsoabbandrdecyyarxvgajlbzishuvbuopursuexohbsgztzzqgzztabbuiyqlsecoxvjbsxkwpsxkswbaxcvadwuowkzqqcfnzqqtpbpetnrnlunlyilehhsfstwkxdywtqsirjonyhakbqvaaiejpypjrnurquplkhverjrprtbujyukgatyakhuxdlpzcamkvqdhjsyewsoupadrtbsgkodoztpbvbnrtqyelyjjszdjzgbujvaujekkzznudbnytndgnopintrobuilrjhcprmqscmvdawypzffpuncpeqtbagslnvagjsylfwqhsrwtwbisqmkvedyejqqynsezlcmqadzuuvnszxmplwmpbkwkdoiqgorttelthkqdidxhdlyqinglxewcsgvavmuoqhjzszeafdjkpjazwikwmiygrthoidcyknacpeeuipgzzgyvrirdtsmkntyvycwipwngctcmjilirjfiuxnnrbzeuxcszydqwsxalbnukacdminghcvaeueytitugykeqjfbnuyxuacgkpotrjtvfywagruprhvhsakfuieplgxvxmppvimdikdrbaishdbbgmhawlrhupfrbwiygvdphjijjqdsvhtbvceroxbkogbpckqihtzoejzpbfhxodajfecvedfsljkpvaacvbsclurmbzjpemalschwioptxblsdlwymrcxnukovvfzhfkajtyrinnhqyctlauxrwxeqjulgbmogzqquojeewmuuoqfokfigcoznlmtmzjvazluqubwtnqpdgvtscdzgsytfkorlymnzzkpwllpyeedmbyffcglwggbqvsethrsibkgovvobcrofqvludyqjfrzalfvuzndazjrvhfylxospjfjmebxjsxlfegadvfgvqxszcqkbffsqkdfoeczybkggqglonrjdobdtrpwywrphuwxbyxbahhiaptocnxidanwrevsbmhkidhjdenfounqmjeqwdyzdnywutovhxhpcobgvoljkbzwkfnginhndflxaauhxbzcpaikqtvcwuzgbooldwygbkdemxllyknqmvacryhpsgwwwmhziiimslqglbrlohbaecfvamnuujssvatgibscpiialblbinenrlktxxptiilgkgmuigwxqgzbhkfszjfsurntrfoznbfzhttpzropxntgayazhhudzhwsmkrblzcssvksoyhnoawoywphgjkftixhuqlhpnailmczmjpamlomjewppgwkrvulmfvdsxnfjphvbwwnhmbssxikgeuxaokmvfrqcfvnucjvahkjtocmlkyrqsqqjdeekwupbscxunvvwhgqviehucalwtbfyimiegzhyeevtbsqjyiejoldsooojswhciriqrprvvoqxiggiomreaxwonlxhjgjtxrjoiclgscfaknjbzcfzbcppnmwwsirszcgkfuqzwvciiljjppjrryienechmtzoviaccqeangixtsiijrbasjghqkocdqsaysfckjezpoyighspyursdxzthqymgspgnukxfozwcxelewcfsuxyrztbptnvmcdzynydbxzdvfqbetgyngwgfshulvrxzuyyjxdkufprkitqbzpofnumfeirzzqyvpyemcqijiavqtmrudhcqdowhxpiyfjwuhailttudtstoemkjvmzadxkcmsasbymlzxyuqvxlnsbtelcbybbbzldlgfdjeswfrvbhqyufsvyygazedahcomqwuvfapchgziprilwaguynwztzbdeprwnlttljxurwcjpmulmbhmqfllgnokegistclfnkzeienxqikflrrbwdocsdpwlzoebblonnvvrisjscodvigtnvwfandlourqxdglsdglobugflmbvuuirsprhsewowombuxtadeogawmnknifjqychsjcwhquvexsbqshwgnzebmpovwynucvmnzlvpfqwfixxcguiuvpvhemeamswopjdouyfbrbgbbgehaodvdbehnjjbbgrsruinvpomtxnudtdfihcnigxxrgyuormflusgmjsfiiznbcullwzveyswgsqvjfcxbxdngysqitfjyzxjxyfdwzzcuszdxcaabgohegzmcexafwlcuqfsshxmbyracuadaokgxluzptzuqkymdgfxnejqccqfwqiyhvgegadyueukqvyvbduqhdgmiyreobfvwlbfmgdimzufusavwvlfattirkpimufkhhptnudauxfoqhmoezvhtprmbgupccakjrfymjaighyypkovkkcfbwtccqshsurdlybzhchqjiqasfyepclqyfudxokpidswbvxlxhdjptlhyjopmzhmgcpdszubeozikwtjdyssrecspqhdrpqatfflhaolqptamomrmgmgkoycghfxyvztdfhkhxxxntabhmswseefuehaloamkzfngmznkwlzpnazzsxtzdavhjwuyygkzmzgaytmwglotlpugoqhrqcycauaabmapnirndejkrzfdoclcustkwtoxqqzrcziphbcnfoxxneccingchapdvdcluceydoonqsaxgzuwfyaolgquifaelcrfgydkmtzeozcwyysdxstkbkfjrhpcjhjshpetkdayccxcaphzkdklnrugymjjtudajhvukvuozrsajcbtfngugcagolsjgvlrdhlpeigezygiahdhxlbdqekgpcqxxbpckcupkavmydwbkckjnmnfqxmhbefyhwdsyxjlxgxxjvavxlfnzssrrgyskfsubvmcuxntdmrojrjheowdiquzxvtjamdejrgeovxtjqhsktzohvusoqrlnlwqzauiraoixodgenyogafpxbhltzyhmvxlvtvovkysycaepyvxaamydulyvkfhfeucxpssbrmzvmemnzjnbvngpzemlmtqspuqhmkifzkalqmyrvmutzciaivluqdnixfpmrzrqlucdicugqqzqsjsbeexxjmhhryvlxoblifotilzydyqyhlzorynalujeseprvtcdytyigxjjxzhhmivdhkesenywuoppjsuhntstsbeqcmxpwusdeyxkoyiimxzvpveeoyxjzezeqytosnuymrkapskdplahghlxflghpflhfgvztpxhjhjyzteqegxnnjktuqcjvnscvnbodayohhoibsyhzyuohejduloragvvtwkywkmfrbpsvqcwowlvduazgotguocnloohycprdekbuoximifrdfrjtkrpavfnltxlvmdbqpcndzvpidhnkayempvmnaaytxkrlnsbcwohvmwfpfszhqftibivbitxhfossivwemdbychphbqrsykabsxccqblwrfqzbnfpqjpuqeetwvlufnxakccddobvvrwygenznctfixyfsmbabzambcrgssdqlcosgcrvekcpkawcozcqycebhvkbpnrarguzkluqywfizbknbpfbtjfcgrgxgxayfuxrguigqporrahurmxlyepgvvgcvgaaazuitcomredkhkeyzejxibfewlirrkuujoedsvrjzuwghcfggqfprkvqydhpndlyrqdlluxmrtvyvagesnvmzqcxvlpkpaiismufitszmnxjpfnhskvscxpxlejahskzggfozzolmnxbvmknxifzhxzsdiumcfmiltzlunygcxjxkvnhdsinrhfvsahuhvdsqcfkrgsvddtpbgygahtuqzpibydiwgcokkzdstyxztnablgcscylbntenwmjeqaqaztsusqvldvnqerlgpwjepnrobdsrdjueemawewkjtxazqlhhhqlwfemijfcoqwuukxtptdyocyoulvbsoorvsdeekgucepxomsdhvexzeltqhwkxkbsehwitedwiuvzincrkiojncedlanimraqazbtfgpqakpkxtdjcrspvyugajomardcsewxknpmyewxybhasbrqclwcunpxguzyyvxkjnwjtugrvptptkfvvexqronxioximwsvjogdkowhgqxzceuyitqbkfystxbfuvcfkkkwzhefzdgdhabqvtrhysaurdblygtkqdhrmnynqerxgupeojlodlkuqogrubbmekgrxegnlxnrscvinjwqwjlnxtetuhfasnrpsyffxswpwuzkfycbhnqeiuxeeefwsynmystwmrnlnnvslzusnkyxhxcldjjvhwjircedutojglctlwnainzrkdeomnlwmxedbkixdzhmmjhzhxbrkbjvenltdyrpvxuxhcumddaqmkrthtnruwoalzvoamfvlzuuerhjujbhttcampsingkzigpiuxfiwaccrjmlvnuoizpuojecrpdbxultrrbqteumngxkwuzetqbjzfnququtnfnewowpsrbizbsxxrcqjdziknbhfvasanzzexqwougqvznssrkcwlmhanogkqangbmkzcgpwphtqvnkmxojlbslqitdyuqexcoygxofovyesmohldsygkkwsdzszrxzvnxcmnhalhgdtvkhacfgoregxgzyxyxtnvxciectnlzjglqioxqcrulqcmoammvzjudtagpntowbbojpozufvhvytlahxxiirmcrutgnjdokrxchyymtfjravrhuopfhbjyxchklkyxdxzlvxzpcjiegclcsdhagqaeshofrpdxmcikcjbgsjlalwdebkgibgmvocbhrggekoomyptsaevocyuekaoliajyckgwqmaadqpdhixjosxsqrydtmocozarjinbxpechtfodcztxxnpqmskyjmnioguxvvwmbytwfjbjiugfiwywqiuzwjikpcjmzhybftxmezwnvcufasbrcysyhalzewneeohjhgwmhubdwvkzqossmktvnewrakxeygqhnotuiuzgskhkyzcmmvjzbgsesskqyaxlqtgapfjjrqtrsyfgvpfxvzbprlfqoedgzjhrrsaikwacufipwpmtrpiidparwezvpimgaprlltnfayuxpjqgabrdqtwmzwkpewxfnqqajffkfcjxnbfncyrtspftlpiqoixdypekwluepdbceisjhjcbyjumbferpbunsaxomtubyvgfeyonhqohbivcpzvecquuqrlenfildoqjmewvwmeawacmzyqcqkyielnrtxewlvfxbdsapyalyezyescuecfioubhrifcdmbgpvigtirsptstlwqpyvyorbvijcmoonxfifldqfxfypyjloymlyaccwmlyycplzuvggbylydloeubuungvokxmxkmvmbjnwgwehurgycueyxyulgpbrmnqxznldwzbdvfmpyspcotamuuzamatynjxoxjrvisafznwxfozujbidyhekhziwlgkkrefbwigwvevcsvycwgfupleynpuyxhionppjxxhsbdvwatywcfrrtxqgomelvobidsudrdxtisriopfswyjpxbxmqdzlrdwxxqapvxkesbmiqtaorlgrpddfhesyjqxhixwexgiphwzzqbnhotydzdkgkfgtveaedwiaesrloqmetcoixolwuycedlxypyeswmvbgmoxfddyfrgciubcsdgxqdvfdcaaovdxhtuowxndrvizrjblojifmgkqiksyhxxpstfprsukqcjjlmvavffjnrbxevylsvcnpicicwsubdemrbmogtxwnbtrwrernheerimvggshjwucziqhepdrqxinqmefvkjosvmydegmacqbmgiqwmhmlrbbgfhdpssjoeitkqgmsyngfvxdheruwtwcaffsxzbnfjhpbpbvnocumzxvfpqdiohktpcsoegwppnrerotfqqtrnpxefcotkzozbgphonxdbqjsefzvvtmkilppofiaeybieqptgmyhckbhpaekvswfgluwrewxcxfjpvexjceomhxdkbpfvmnbxhxqovosuvbmsfjckqsyxpchsrnndardjovzmlsghvszbednuvlrknzchosmqjpbznblytufqmhtskgmiseshfxotpdlyumxhnlgifnztuumfbynvehcjgtevwpvqcvarggcltbgoxsvytktxtyhatnvrdtjhojyurchldnbbgybzixybxfdqvbjyushiehevklipajsihujrtivqpyikzrktlrdrzhnjuxyvhrdqlnievdwmdexfvhyizeaylpjimhdvyimlvwrsbnferejonkzmqzmbqvledoadxopukgpnuwrnadenpdcfeoiumuarkcujqlecstporjdrohgfkimozwknslednyogkskenauelxxbfegrosgposchdgmthabtvlzkntrysozxuhplzxaqpfzvlnounrpkcovqhmqacszzzqkbnmtfruafhqzwhphlfcbnqupsoqtphdswqldjfdoovqlehuqmytbonqibhctqhlmzxsjevzvtpgxycnlajoowfyaoatgiguhdmskkshdhpcirqtrbjfxofzegumqbhzgtssfkzitolbfdwwegddwjfdrzphcyijuabzmdigrvjxaivgqbloksrdsjmwhufbvjbjmlrfideklasdbfrnylssweodywhvfkhtxyyhbftoflriqjxqwpisvxxvtgtasavpyvyaarofcipvtmlpdwjytiwoppqjplzngzpjrgqvogsjugaacjaxrwlilbsaotqwshflpwhfcboyhoylzzitvvbjyvjmobjjlowamfgohwnqlnckmmdkihtgcevtigetwatjgbxnymdlchxoudyektmoyhjgpnzmouvuyujyjojlwgzslawvtimtsvzhjatzxqtvletusehqmiiykevgphzhfbqobkpyakvnoqjgwqzjbhjloerformtsejvoywritgwkqegidrlnaxbfqgvhuobyzzpxvifoqdaijhrnaecbbdisldbhtfhseypbiwpzbqhkzazzfbcigkatpeaijkcnirorpfsqxzdyccahecpmpsgewiphsrwdlmwcrovrpypraryguqtlkbrgjgpealhnxdpqtkjikbansytoqozaptibzxfbimqhrgaksjsfkssdtnrjctmtmuunsbrcnhmgpmqixlpifhnyuekyzwsnsobkqupfbbmrpebmpqwvxjvtohspdmdwcgisazadcouruvgmncjkmegcmytrmwpoeajezliczevtcdfpgocuviwjipauoskusvzrgjvhprdrwihczjywtwfbohxczjwrfxlnigvazyrwiaajlbfexmhlwgpvqopxnckykhymfrkqskzdnhklttypaqnseeptibrsjreqjogdbggonsbimaamqpgwvvpdwjvhccylqeotmxibplkdnmrfbxbwutbrewygyysrdikpfurxgdavpubsrcqmxrfbpfioechhmrysoprwstrjnsbhxtvukcyahiqnkxuyqvqekjafdsqsmubjnweaycagmsvyrswhnnozyqedkxwxrxgewmeuqgccyyarqxbdmpekhlosimpzlxfhkkccseftefkwelzqcedkrtezftyqsfycrcfkimdntpjydlqhrtriovjtqhmjomngquqyivncmzapmsxdoqncowygfmrtyhzobrokmcobbqqnipswihzydzgklyfjffziynulrkouaehjwbfgigenfmzskfbrmccksyxjjlelsnuopcwzkcpsookbtoshqwskxpuidatvnoleshgcjvuxlhahvtolrgyoysybusyjijqaswedtbceidldycqpiogiiejcyjmgucimanptoszyvnbtptkziqisxtxvdjexnmkpzbiptjnqwqjnkwnumvololhtulrjzdyzeiqaugsswegiateoqtaeejybwrkvulwavncpvvirzoczjgnzzpfgyfhuwtsseovcdxryubstpuuackzezhkamrwlkodrdatgamhuozqdtkgvufbwolwbcumpjriosbwsndmbcchvpptlwwjlihmmcablrjzlm
vdcbsfdwobndwzasilaqznuzqfscgeodjsedykcolpshquzbhctgpnhhubjchahtsmysyahjsbqkvrlcvgkmttunufrcfzvanvulwduqemazfodbupnoihddpvhuwewjztuxwqnbeocjcikwxamgjslypsvlwtuxmqvjgimkyovcwibwincthnswhphfidcxtxgbiungijjhtmddzhwhwqfdhnkqqmpmmxnurdcbmnkhzpkbwgkszpxgchyvwnhikwedzgfnuputfewdngymwvuyftvdgeltbpwcxdqttmpatldisbwozqoejkhsounrljuknmeiativeldwpbmosbudndxdxkvkwrulfyvhrddyqiwfmjvekpjzsjcrtzbrsyezwzhqemoxwkeivaohragkjldekhwffcebcntgbjdyuiirkxzbxhnisrmfyikflqipecxfldfhnqzxpayohowafifftrkghsvnwsvixcrksqjhqkvyyrafchkvywbhqyxpssxquoaphmwzwuzunzzpilkijnqblpqehpudewunitmgnocandsyocgzqybdnrhwhdanawckpqrcetfuxxsnbaprzqxmjejsilhkhjuzcnbijicifwxhxmawcxkoevimiqwsbsrdismrdqbipyrmlukptufxqolyejqhcjnkcbdhrepgejurfehyzoyrcjrgtkqxtdjxeoevuweyfyqkfzkenixquoynyomutvrxjwvdubdzztlguxkigjaaaaparbukymihkfmggphfjsmfrynxkpzkqqkjtftrtdafimlocswnmksdkiduxeepxpyqwukpxkwgxhubbqqpaiulszhsemhdditzcdqzqmfpvcqyugnvqhilhpdndmqgulhyrxahlhwijmgeuvbmflxoaabgptolewkxvmejtarfoajivmxaxuqzxrfomwztslqpxvyrxswmshwpttqsqirpczdovejpqaenxdguveipnfegawaqfshhtkxophdhjhugmdcjhlyvsfdsbelgysprfnhwukddtzlicntmaujszonauyjsqalxnutjgyoaazkcpdqrxbkwqxzkxkfnksnynijthyvhxflolegifshvpiimsnbefqcszmoimjrlpeaciimoavlrdtdxigcqzgiyuyggizszdsbmcnccjntojymtgojfwudrslxakpbojcclsepdtiteifypvjwsdajyniyaacqleszyyobrzxyhcwyahvulxflmnlmnnczswysuowontmxxkvxrsrepwpcmbqbovcircborxcgsodpyznptgwjdlnrmdsdavlsxogqlkxdyatybipvolgtxtklyfozaatzobqclnhlpcjrkyobmuujphupmlqonjpdmffzupmmrvfewtfipbtgipvwamknxcrmhylepysjvxntsudhxyngokeqwrgwtxicxvgptayrxnmphqygoloeytvukbsdaafzwooromkobxdkpcrfpfknyhkkkenkfvldjawzohnqgravvtamzkcztokdsxpzsbeddbdtkqjqjmlgfntgaxgtlqxdpofipjnskqmwjxmslzbtpuzptfkevhjlyovnakikdwjmvvghxhcmdbdwjncexorveoiebsreoaqmxytuixilynkhbooychvhyflzycfocxaavvwfshrtudavtqvwasfyyqzyvemxdnzykyeffxybcaxvruttnyrnpslmyxjbmlbzlheqgcrkcqgvnzocahppbabzxmcmzglkppcwrwgvmorbqfdqnshqsiqswueyapiqgnoxjwuxllzbtetgxawriojglpengpdmctlnqgkdrlekqxspxrghhqpshugollanfmcxsmalagwqfqhehnlrfcjnyrbjddykpahjpjvppthujoytdlklpvyonbxqgyawyjhpseejxndjbdehqqsflstyvtqbrszrbhhvlnelbjwemaleqdkbxdcsysurntjqcsmqfsbgezlszwxrchuzmwulrqcglnwofkglfjtjiebhdyahfugutchmslsezqugbatijnrrtsawtadawmupqbdjpxpqojwrjszshqlaknzdneelsadjegstgjjushndbmxieijoviukoyxhaaqejkxptilnsyqtkncqvngsxaelabsbckhlufcppnchlsdxhfneutwrwccwexzihhveoxvdkynvsssaxhgtcdkyfoxllytvfobvlwbvwosrgmtfvzayckykavxourjbhmxtiyqholywxrdvqdtvprhppedlvomdalyllqszbsxbjcwbfrywifozktkhixmkkmxwdrxgjvjuxfwfwudhargmlrvvqkhawfybywkittcszazxvdgxunlhgicysmarrzurvezqyeizeiybnfajunrcwvaqhajabesyktokxzlejmhwtkfnxyrvwrmdtxgvdytorkarjoxsaeotoviowzjssxxlvdiadeoxoroxflrfrfygcguyhfszdqmatvaxzrupikopxfwomuwocsplyjkdzwfttfsuyojiyxxvetjqpihtaweyfodhnicgqudoimximudqqohhwqbxmhxtwdclletbawsklpsxlxpbmylkomjctjyrmaczfydhuvsfkkevkuzyskihyultdjlrkpqrntykoqpaduypoznilxrjrdcumpnyfepuzqeqgwqlqoagppqanijenobbdoakurhuhnkqjcbbtehityjgiunviowoewazqjtxxfnihrkaxrlsrubzqouzetpirrhhbcfyjugtnqvkkgfbcgdtuzuysjikasrdwybgtkbicwvofashgvacuucnfkzieqlbrpjkbkudipunpmvxjxzfubuzotjsmvvdmepnqjszbmoqalqljprdtlehhqbtnxyzdnmwygxzvlqvxihixansntbujdpwcnvhcjdbqaalosilartarisfbublzthbifkloooeqorejaplrkljueqwathzoqcxvmkmcastqkxzmpldbyowcgsecbfqtjpryzdabxvshtrtkezndnjhwdmygtoadgrdfwdhtzbduuygzxtenfljkzjrvxtydkbligubhxgdrfjqcfupkiaujjnejgeosfbaoxexukbmpmcutzjdjmasvpxgwbvqjwtzuxwojzcbmhvhggnrsnjqegwckrttqmsmlocwqfxcmujubyltlulsdiunbngrbafoqilgnkkbfwviuidicpahxuuakcsnezevhrbwboxikuqecumhjooillixpcmwcqrlhuilihtuemzggnpregbptjmioaesrxfasplcxfxbryjzlzqpfrgycuisvpmomsoghajehihagtztsrlzkrzoojhjytxnlntvnebwojwucvqwobxyuwnihwrgrqtfgoatvbsjmogqmwmazlbtjqcrmvxfoskuikpfohrawzrivfkwtlpcdrtppsxdmhzxuociwvkuuderlonecdifwexnyuqndrkxgohemuagxeykunqysbepfdefzxscoecuvlahfapfeprbdizvjdmqirvjoomcuqzpdzyjaoqgdhhirhecmqsxjqgxgucakbsqcqzegrnkausudywqrrpahvanqenchhsjytqemdqnxlhdjftcwiffffsvjiaspsbpmtwywmnwzwzlcunaesgjzahkkhcczgrnznoycbudyvocpeetymeaplkzupbwvvjwizumbqqblgfakjvlyclnpxmkmqgjlrgtrciutyvegahtleejgrwwolibbqmojsjaxrwqrrwytfrhkvssorqccaffqstakecjwzznsynofevrbnkpgcsidzpvrkxepcnlbpavnojuugmwwyncahnfhebypacecsrfhtbwjmqevcctapvdxkigpjeemjkobduiwxgglwkgzmzbdxechniyyncmyobbrxjqwrwhniqowrszowcylkymzdyzrbalylbucxeqhugdlyecxicivawwfxwxywizklvmkzervlwjlanilptgrrcxoawpzgqjrlvdncuipsrauelfvenpxqomsmdrstalgyotakcpcvryccezirogjeucqxtkswvyuluuxylbtcaxhgxpxlvjqrlgqgricojycfubdfdwkfutlrikegtwxgdqpwatmjsqqmstuxsgemzrfjblrxirfnhulhoxtiqjukdqhvynjxeqjhbaejrmwyghiwhbezkbjprsmqfvpjnaspbxasjxtrgbopcsootxgnrsfwqwhdxauyzvskuldaorssmihhgpuzjzwzwffvfbtgwnsqbwtpplibvrjbgfdpfzrdeyymztuyinojjjzyujcqaltiqyzxxsceqcssxmqgzgpkqqlmzpebaajsyjswbwcuzuowieekkuucmhpowtpytztuknqnjuhkqvhybliohfqwmhklbblwaeqmriadejnuhwvkidyrkrpxyzkbbvadcsstdsyhdmekizvscvmnobmndyqgtslvldrqxpxbdbnmakefgquuugjxgcdzuoxhuqxrhxulakxbudiawcxqkinqksrhiqqegoyqnsbncyqxdyzzcypohegtyacjstnbjlrweslischvchvhhmvqrekpemywhoxqzqmfiyoacvyeevnmhjcypoqvbqtietbejpjspzurvuybplnxwsxlgnijgcukvxqgmcacbxtyrtajfpgbhfpqvxbbbxnyuefhgfljceiwyiffxlihsxznxaoaaczugedoloxotfktppapciwuixkhxyhxcgukmxyymymhdycvpcktmipufzbealccryngvnejlqqrqumfwwalgpflrjpruttntitpwxyhpryhlmokkovqgcdxnvqjqjxkuszqszzjsargmfsxwppcrtbfqrogcnqwiroarollocrckjziyrmsmnzcgpiifbhnsvpjlaxzfocradbawnuictmilxsqybfqzwckyzmfpqwrvxusmocokryvotnouuetqieojsuzissdsmxebcvnttijmxxhrdchmivxaryikroefligndtixdrlaquruxaifyfgpeqbxgfcsqlhtgssklemcyewxegdcllurdxokdtetenokfhurnhtnnrltxqykbscgpsquluprkecpnyiahdpwwcqtsogvikczcuwqrljbplqcmbetewqdyiytweqgouhtpdlgpuhgizlucrpjpfmqpkjnpbtfwdangnvxiegqftmimbrcjdsypdmgehocmopvcmumqaewvsgitxkeccftftalcoopefkiueukhaicsokonusryzldsnrvdhkhowsiamvhndkhuuvjrobpnovidmdgvppjnhunwpxjujsqdoawcdmrthbwveeqvtbibxyxmxijgazlobiseumzdnvauzsrvtcwravfzfoffqqwraqywcxzstbmutdppfnihinipenxwgtnglldojcieeuyzzqohdwqomzdsmaosvdzhpcxagfembemauchabaopzthnwxgraharlxrtevifcwiwyrwzrmqqixeeumxxvyoixibcdjhhhregjcharyrzxxdulargyhoypravdjckbisklakcadbxcgtnikvjulhjfhgisjutrnfcpsgpxjoaripaunjoyqafzgnrrinjxsnmkubkfrkxbbxwoimpyouzxkqoufxrylfkhiuozglbkkzasnpscmrbykpupnnnasajawxbflepvfpovhixvaytkppbccrewrnypnbuygjvnbjiishduhygxnhbrygprvnhiobiwnekopswjabfjblgqtihtowlllswzveyikiwaculevroycuoxextuveggycitigctqavsvgzsxprcjfbqfukaashywrufzyapyvjtdkodzfhlmibrdnsdgbeeuyjtwlkwitqmegrflyqzgrrlhlrpmvtgvfbrqlnzefnkngqyeiymarajcryoorwjwxcniroozdbmjtnpbnbdebmgukwkcutarxnbrdrqgserlrgpeisklfsirosvkowdnjeepywxqbpeuvvbdnlruezmutjfjfixrpbgnydfbslvqgytwkmqqnemjqtsvepmttuitypusbrijsefcsyugeirucjsgzebuzjnzyjtbcenuiuycuskzbbvflplmumgvxvwxepbgtobdibgduqexsbefrprndziauexyvygpojsxlachtggnjksablnekxegbdezcmosyipllrsezarjmjlnwbrgyxmcasbegpxezmpkgjohjhqvqekofbudyifzcifjxcpzrfjzqagchzzadkokllnmtvnydshdxwcqdnpupxwzyvbdfpntcbfyyswbmdejbibfyqbnqxooupschhxjichgwfkkiqumzxrzquogtdwnsqrzyolisuroabbktvwuuptkjiqcnpshfljfauouohlqkmbdjxydptoadgfqvxydkhikdyhtfskpelvnktqzoecslhiigilqruduskqacarglovxjlzysbqfianqjbgavjxpvnrzplfazcxjqwhkzxphxexifglcrkunznmoyuqyyphooqynppxouuxbciguucjtpvhorxoqmxgapfqeunsqjrumbcgverovmxjgwzylyennjdrgqkwadsofuuaalrwzohhnhhyfmltxrmdjycjcwxhrthrgynipxrcezalnngketqorsztozchukbdkqnbnedrfffsvldzgtpynrtdsynmkopueeysjblqjqjeeofkjvkyogbgequqekmlqkdboqsxjdbnrgzcdkatsdzyuuoygalyloazhsyqvzdohcqnosigvigpeuqmvbkiskhzefpbgurpyhenznvxxcodweptibbcokbsrswzonpmxtzyixvfzkixqztabwcphfjazfantpaqkbotymazwjzoispjoraxzkyyrymkpmcbntwofxndgorqggcxacuzouxgujslxvnnojbvgqyofpfnyjmynjxcdwkaiclfzysnkvisoijvyqiyzxwmgvqltalbfzhezbujzeennnindslephqxehlxjyboxktxlnimrmzgbjteceitnbrtkertcskaefzpuhenwduxnnerumkhpdbzhuvkofmsmljguntqrpogdszzgjgypjxyduktbwlnjxvekpudekljekilwrllaijgfubgsnwckriwgcannlytwhgsarfaaqihmknfzjjlbrjjvjykxxevgkngcugekrlxdaeekprngaybmzojwsgccvigpqkbjxamyeskvlzbmxfaytlunryrmgybzkeiifxijrsfdrirqprpkclzvkrhqrkrdoaltzvfqnmvgwmxmdoyhzycjpjcivtlkvzfuuknkwiqvvphadhkdfmmwyogtksfftlcnvrzuzqrwfazjhjmpxalvrurbmwghjkwhbwddoubtuaeblsqjtegkyxnmwtvferohnrkblmxfmdjawbjrfpdfpqtnloupijxvajzovytkbekxgvqnmttbjoqvflmnuliwvjmsjgclmoksjbgwubzgpqbudpjzbuvydiqnqvaejkxvlftggsoxkpungdmhxkhduasmxsqgcpdquwycrmcbdwrjbdtbpaelcwzzqsishlieiiizukcxithkzalqcrcfnbgdvoxdaijkqtlnenkojtaivnaaecftglybcygcgroylznroafztgjrtkryowtwjsalqipyafylgmcxmjwfpgylspjgnedxwdkolcmnhlaqxcnjojqdrpojezqsgvrcadrnhdbrqbhnguyufrzxgqgmrwgxtxatdthkyibplketefnkwphcfpqymxwhwybztimrsnifapzeuoqqdzskpkjdhhkeflfyvrrphcvhrwnlkgbqfvauflzpskvxxaxturidtfmkbbvohyentejyqjnitiiqlhlhyuktbydfzathyxwrdfstohejsocfxnmyjyrlwxqvxleyiarlgjhwtngldiqaxeyhcsuypkvoxamfagsgpzdkolvrtnuqtszvmtvbfrscrgjtmcaedfosqmllbfdvadsmyoqefigyqsrdutjxyxrqldbnihkkmcxkqpqxzzvprnulgdihdcxofbdpknawqzigozenybepqzazckgfmfutizjsnlodkxlayrpwttllsnkvzqcoyyhgyszlfpqrobrmvgiqcvbukmrmeuacujjsekfjzvdqzucudnmfknbxztjgnjijutcyfhkhfnxejbaoqmvbzxabqjhfuroolspsczzhownzanoqbltcitdacmhweynrqcjsdjzthmshbiycurfelkfpxmmbkzudddvgoxbwjtdncdryvwcijjxgwljimdlpihxzgyvruaeygwwbuyldkilgwuqizcaklxjrygisgpqmnmphmcnwnyejtvruzremrpdpvnheexqrlibzkoyxmcihzaeytimmyrbvfkzljqdwaewmsukgyuqyuuyqclcccgyjqxvapawreueyqqgpkwphqpxvcbzfjzqaznconagtxmtncccmytvrjsmlwnsfnjhmyjcomkjjwdwyhbnfuiyddmrbajinuqbvbdjnqsymxxneycmumkapxrsxcbmxrpsusdiivixtfkzfolaawasttksvneuetobnrlyptvkzhjgxvgxtirmdcebpkvwfmxsdisudpeeyolvltteekqhowigggensdfxnasqpwvomijxbebfrtphpznxftkxwsxlspchlzxyjhxmnzueujmkibjovwntokfibjrpipntymfllzsgiesthdjczwwpjdxkmrzwgopgburoujwepqxxuibthzlqckcobemjubpxyhousmykdyhxgisniffmqkbrqpbkrskpbajumjephnoqvjffolsexvynkbzdtluvldrypxnykeohnupdhhieeitqlsweeqbpwsplpdjzjajwwyzdhjjltcdewzjaqmsofhzwmkyvkhtgftlmeuzyweevgpvycpmhxlfjvdhikaorvafawgavneqtunrwddfcqmllquvcvmwqmbskksfxzvqtljromyqckdpcylfvxblleexqydnxafslojbajtewxuyxhdsggftnlqdkvrhwycjnllpxeutdqrczxwffcaspqyzorjkplvcyisxpoqsekxdjtkqxklncjmqaxcpkyujiogxczsglplwivmghzvlihckhgcrgwapmjookguxxhtichqlhlwrsaezjgtpevgqgvgsdcpbjkjnuzybkwuexygigzxmwgedbkvemlfxxqkrrkubhpigpqoyrnmntrqudmbqzinwzaoskiurzezrunplbbywurtyfuqeefaffqyqbujayjruwifzmfygyrednwhrckxhcvxdrhepsxjogqqsxqyyhfbwblndvmnxjkdathrlgacmsugskhqtmrppeevzrizcucdqlubrxfgrzmjltbghtxxxcuzveaxyecqrzsiwzqpbdzoyavgvufvwzwtfwtfcvwtuqbspuiqxjfvlcdhwievjcooyhucfqvbiyuxseqpnxnyzqhxbnskpjbpsxrxpmzxnvufzkxohkoicwgdlaqbjrscqkbfyaclvyrwlokuazdexliilalxtebjqcoodsaaqtzbjjylkdphozsbzfyslbdbersjjulcnkfywdjggyqwykyzpyubaxcgrupcoaedlmbhpkpylfulpukhvgixekdvhsxxsebfqeofrefclcpdwbktisqmevjnnglimopcueklkppvreyqgklqcccjxnwnvjxixmksqwfcmvafbaxjljzpndymqvzmewuelgwbdbgrygyagwjrhlhuofghcivjgrnrxlvcmbvn
Out #2:
590

*/


/*Best Submissions:
C:
#include <stdio.h>
#include <string.h>
 
int main()
{
    char a[10000],b[10000];
    int t,i,j,k,l1,l2,count;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        count=0;
        scanf(" %s",&a);
        scanf(" %s",&b);
        l1=strlen(a);
        l2=strlen(b);
        for(i=0;i<l1;i++)
        {
           for(j=0;j<l2;j++)
           {
               if(a[i]==b[j])
               {
                   //a[i]=' ';
                   b[j]=' ';
                   count++;
                   break;
               }
            }
        }
        printf("%d\n",(l1+l2-(2*count)));
        //return 0;
    }  
    return 0;
}

C++:
#include <iostream>
#include <string.h>
using namespace std;
 
int main() {
	// your code goes here
	int N;
	cin >> N;
	
	string str[2];
	
	for(int i = 0; i < N ; i++)
	{
		cin >> str[0] >> str[1];
		//cin >> str[1];
		
		int arr1[26],arr2[26];
		//int arr2[26];
		
		for(int i = 0; i < 26 ; i++)
		{
			arr1[i] = 0;
			arr2[i] = 0;
		}	
		
		for(int i = 0; i < str[0].length(); i++)
			arr1[str[0][i] - '0' - 49]++;
		for(int i = 0; i < str[1].length(); i++)
			arr2[str[1][i] - '0' - 49]++;
		
		int sum = 0;
		for(int i = 0; i < 26 ; i++)
		{
			sum = abs(arr1[i]-arr2[i]) + sum;
		}
		
		
		cout << sum << endl;
	}
	
	return 0;
}


C++14:
#include <iostream>
#include <cstring>
using namespace std;
 
int main(){
    int cases;
    string a;
    string b;
    cin >> cases;
    for (int i=1; i<= cases; i++){
        cin >> a;
        cin >> b;
        int ta= a.size(); 
        int tb= b.size();
        int cnta[300], cntb[300];
        for (int c=0; c<300;c++){
            cnta[c]= 0;
            cntb [c]=0;
        }
        for(int c=0; c<ta; c++){
            int alm;
            alm= a[c];
            cnta[alm]+=1; 
        }
        for(int c=0; c<tb; c++){
            int alm;
            alm= b[c];
            cntb[alm]+=1; 
        }
        int r=0;
        for(int c=0; c<300;c++){
            r= r+abs(cnta[c]-cntb[c]);
        }
        cout << r << endl;
    }
    
}


C#:
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace CodeMonk
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] poleA;
            int[] poleB;           
            int t = int.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
            {
                int result = 0;
                poleA = new int[26];
                poleB = new int[26];
                string a = Console.ReadLine();
                string b = Console.ReadLine();
                for (int j = 0; j < a.Length; j++)
                {
                    poleA[a[j] - 'a']++;
                }
                for (int j = 0; j < b.Length; j++)
                {
                    poleB[b[j] - 'a']++;
                }
                for (int j = 0; j < 26; j++)
                {
                    if (poleA[j] > poleB[j])
                        result += poleA[j] - poleB[j];
                    else
                        result += poleB[j] - poleA[j];
                }
                Console.WriteLine(result);
            }
        }
    }
}

Java:
import java.util.*;
import java.io.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner s = new Scanner(System.in);
        int n = 0;
        n = s.nextInt();
        while(n-->0)
        {
            String str1 = s.next();                // Reading input from STDIN
            String str2 = s.next();
            char []c1 = str1.toCharArray();
            char []c2 = str2.toCharArray();
            int []cnt1 = new int[26];
            int []cnt2 = new int[26];
            int len1 = str1.length();
            for(int i=0;i<len1;i++)
            {
                cnt1[c1[i]-97]++;
            }
            int len2= str2.length();
            
            for(int i=0;i<len2;i++)
            {
                cnt2[c2[i]-97]++;
            }
            int cnt=0;
            for(int i=0;i<26;i++)
            {
                cnt+= Math.abs(cnt2[i]-cnt1[i]);
            }
            System.out.println(cnt);
        }
 
        
        // Write your code here
 
    }
}

JAVA 8:
import java.io.BufferedReader;
import java.io.InputStreamReader;

//import for Scanner and other utility classes
//import java.util.*;
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        // Sample code to perform I/O:
        // Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String name = br.readLine();                // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        //
        ////Scanner
        //Scanner s = new Scanner(System.in);
        //String name = s.nextLine();                 // Reading input from STDIN
        //System.out.println("Hi, " + name + ".");    // Writing output to STDOUT
        checkAnagrams();
        // Write your code here
 
    }
    	static void checkAnagrams() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String ip = br.readLine();
		int count = Integer.parseInt(ip);
		int i=0;
		do {
			String s1 = br.readLine();
			String s2 = br.readLine();
			System.out.println(countManipulations(s1, s2) + countManipulations(s2, s1));
			i++;
		} while (i<count);
	}
	static int countManipulations(String s1, String s2) {
		int count = 0;
 
		// store the count of character
		int[] char_count = new int[26];
 
		// iterate though the first String and update
		// count
		for (int i = 0; i < s1.length(); i++) 
			char_count[s1.charAt(i) - 'a']++;
 
		// iterate through the second string
		// update char_count.
		// if character is not found in char_count
		// then increase count
		for (int i = 0; i < s2.length(); i++)
			if (char_count[s2.charAt(i) - 'a']-- <= 0)
				count++;
 
		return count;
	}
}


Java(RHINO):
importPackage(java.io);
importPackage(java.lang);
importPackage(java.math);
importPackage(java.util);
 
var sc = new Scanner(System['in']);	
var len = 26;
var t = parseInt(sc.nextLine(),10);
for (var i = 0; i < t; i++){
   // var v1 = new Array(len).fill(0);
    //var v2 = new Array(len).fill(0);
    var v1 = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
    var v2 = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
    var s1 = sc.nextLine();
    var s2 = sc.nextLine();
    for (var j = 0; j < s1.length(); j++) v1[s1.charCodeAt(j)-97]++;
    for (var j = 0; j < s2.length(); j++) v2[s2.charCodeAt(j)-97]++;
    var sum = 0;
    for (var j = 0; j < len; j++){
        sum += Math.abs(v1[j]-v2[j]);
    }
    System.out.println(sum.toFixed(0));
 
}

Java(Node,js):
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});
 
process.stdin.on("end", function () {
   main(stdin_input);
});
 
function main(input) {
    input = input.split('\n')
     
  for(let i=1;i<=input[0];i++){
        let count = 0;
    let newinput = input.splice(1,2)
  let obj1={};
  let obj2 ={};
  newinput[0].split('').map((ele)=>{
    if(obj1[ele]){
     obj1[ele] +=1
    }else{
       obj1[ele] =1
    }
  })
  
  newinput[1].split('').map((ele)=>{
    if(obj2[ele]){
     obj2[ele] +=1
    }else{
       obj2[ele] =1
    }
  })
  Object.keys(obj1).map((ele)=>{
    if(obj1[ele] && obj2[ele]){
      if(obj1[ele]-obj2[ele]>0){
            count += (obj1[ele]-obj2[ele]);
           delete obj2[ele]
      }else if(obj1[ele]-obj2[ele]<0){
        count += (obj2[ele] - obj1[ele]);
         delete obj2[ele]
        delete obj1[ele]
      } else{
         delete obj1[ele]
          delete obj2[ele]
      }
    } else{
      count += obj1[ele]
    }
  })
 Object.keys(obj2).map((ele)=>{
   count += obj2[ele]
 })
  console.log(count) 
  }
     // Writing output to STDOUT
}


Python:
input1 = raw_input()
test_cases = int(input1)
for i in range(test_cases):
    count = 0
    a = raw_input()
    b = raw_input()
    a_list = []
    b_list = []
    for i in range(len(a)):
        a_list.insert(i,a[i])
    for i in range(len(b)):
        b_list.insert(i,b[i])
    j = 0
    for i in a_list :
        if a_list[j] in b_list:
            count += 1
            b_list.remove(a_list[j])
        j += 1
    print len(a) + len(b) - 2 * count


Python 3:
input1 = raw_input()
test_cases = int(input1)
for i in range(test_cases):
    count = 0
    a = raw_input()
    b = raw_input()
    a_list = []
    b_list = []
    for i in range(len(a)):
        a_list.insert(i,a[i])
    for i in range(len(b)):
        b_list.insert(i,b[i])
    j = 0
    for i in a_list :
        if a_list[j] in b_list:
            count += 1
            b_list.remove(a_list[j])
        j += 1
    print len(a) + len(b) - 2 * count
 
R:
input <- file('stdin','r')
n_cases <- as.integer(readLines(input,n=1))
 
l <- 0
while (l < n_cases) {
    ana1 <- readLines(input,n=1)
    ana2 <- readLines(input,n=1)
 
    u1 <- unlist(strsplit(ana1, ""))
    u2 <- unlist(strsplit(ana2, ""))
 
    n <- 0
    for (i in letters) {
        n <- n + abs(sum(u1 == i) - sum(u2 == i))
    }
    cat(toString(n),"\n")
    l <- l + 1
}
close(input)


Ruby:
num = gets.chomp.to_i # num of test cases
 
num.times do 
  a1 = gets.chomp.strip.split('')
  a2 = gets.chomp.strip.split('')
  common = a1 & a2
  total = 0
  common.each do |elem|
    total1 = a1.count(elem)
    total2 = a2.count(elem)
 
    if total1 < total2
      total += total1
    else
      total += total2
    end
  end
    size = a1.size + a2.size
    deletes = size - 2 * total
    printf "%s\n", deletes
end


PHP:
<?php

// Sample code to perform I/O:
//fscanf(STDIN, "%s\n", $name);           // Reading input from STDIN
//echo "Hi, ".$name.".\n";                // Writing output to STDOUT
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
// Write your code here

fscanf(STDIN, "%s\n", $entryCount);

for($c = 0; $c < $entryCount; $c++){
    fscanf(STDIN, "%s\n", $str1);
    fscanf(STDIN, "%s\n", $str2);
 
    $arr = [];
    $ans = 0;
    $l1 = strlen($str1);
    $l2 = strlen($str2);
    $oa = ord('a');
    
    for ($i = 0; $i < $l1; $i++)  
    { 
        $arr[ord($str1[$i]) - $oa] += 1; 
    } 
    for ($j = 0; $j < $l2; $j++)  
    { 
         $arr[ord($str2[$j]) - $oa] -= 1; 
    } 
   
   foreach($arr as $a){
       $ans += abs($a);
   }
   echo $ans. "\n";
}
?>


Pascal:
var 
sum,j,t,i:longint;
s1,s2:ansistring;
a,b:array[1..126] of integer;
begin
    readln(t);
    for i:=1 to t do
    begin
        fillchar(a,sizeof(a),0);
        fillchar(b,sizeof(b),0);
        readln(s1);
        readln(s2);
        sum:=0;
        
        for j:=1 to length(s1) do
        a[ord(s1[j])]:=a[ord(s1[j])]+1;
        for j:=1 to length(s2) do
        b[ord(s2[j])]:=b[ord(s2[j])]+1;
 
        for j:=1 to 126 do
        sum:=sum+abs(a[j]-b[j]);
        writeln(sum);
    end;
end.


Perl:
use strict;
use warnings;
use Data::Dumper;
my $T=<STDIN>;
 
 
for(1..$T)
{
my (@letters,@letters1);
 
my %hash1;
my %hash2;
my $count=0;
my ($value,$val);
# my @keys = keys %hash;
 
my ($i,$j);
my $string=<stdin>;
my $string1=<stdin>;
# print $string;
chomp $string;
chomp $string1;
@letters = split(//, $string);
my $length=@letters;
 
 @letters1 = split(//, $string1);
 my $length1=@letters1;
 
if($length>10000 or $length1>10000)
{
 
}
else
{
foreach(@letters)
{
if(exists($hash1{$_}))
	{
	$hash1{$_} +=1;
	}
	else
	{
	$hash1{$_} =1;
	# $count=$count+1;
	}
}
	
foreach(@letters1)
	{
	if(exists($hash2{$_}))
	{
	$hash2{$_} +=1;
	}
	else
	{
	$hash2{$_} =1;
	}
}
 
 
foreach(keys %hash1)
{
 
if(exists($hash2{$_}))
{
	if($hash1{$_} == $hash2{$_})
	{	
		
	}
	else
	{
	 $count+=abs($hash1{$_}-$hash2{$_});
	}
}
 
else
{
$count += $hash1{$_};
}
 
}
 
foreach(keys %hash2)
{
 
if(exists($hash1{$_}))
{
	if($hash1{$_} == $hash2{$_})
	{	
		
	}
	else
	{
	 # $count+=abs($hash1{$_}-$hash2{$_});
	}
}
 
else
{
$count += $hash2{$_};
}
 
}
 
print $count."\n";
}
}


VB:
' Sample code to perform I/O:
 
' Module Main
' 
'     Sub Main()
'         Dim name as String = Console.ReadLine()          ' Reading input from STDIN
'         Console.WriteLine("Hi, " & name & ".")           ' Writing output to STDOUT
'     End Sub
' 
' End Module
 
' Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
 
' Write your code here
Module Main
 
    Sub Main()
        Dim numTestCase As Integer = Console.ReadLine()          ' Reading first input
        Dim numOfChar2Remove As Integer
        For ntc As Integer = 0 To numTestCase - 1
            numOfChar2Remove = 0
            Dim firstStr as String = Console.Readline()
            Dim secondStr as String = Console.Readline()
            Dim charHash As New Collections.Hashtable
            For i As Integer = 0 To firstStr.Length - 1
                charHash(firstStr.Chars(i)) += 1
            Next
            For j As Integer = 0 To secondStr.Length - 1
                charHash(secondStr.Chars(j)) -= 1
            Next
            For Each item as Collections.DictionaryEntry In charHash
                numOfChar2Remove += Math.Abs(item.value)
            Next
            Console.WriteLine(numOfChar2Remove)                 ' Writing output to STDOUT
        Next
    End Sub
 
End Module


*/


/*Editorial:
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int number_needed(string a, string b) {
   int p[26]={0},q[26]={0};
    for(int i=0;i<a.length();i++)
        p[a[i]-97]++;
    for(int i=0;i<b.length();i++)
        q[b[i]-97]++;
    int ans=0;
    for(int i=0;i<26;i++)
        ans+=abs(p[i]-q[i]);

    return ans;
}

int main(){

    ///freopen("1.txt","r",stdin);
    //freopen("1a.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    }
    return 0;
}

*/