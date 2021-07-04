/*All Tracks -->  Data Structures -->  Hash Tables -->  Basics of Hash Tables -->  Problem --> All Vowels
Tag(s): Ad-Hoc, Basic Programming, Easy
Vowels are very essential characters to form any meaningful word in English dictionary. There are 5 vowels in English language - a, e, i, o u. 
You are given a randoms string containing only lowercase letters and you need to find if the string contains ALL the vowels.

Input:
FIrst line contains N , the size of the string.
Second line contains the letters (only lowercase).

Output:
Print "YES" (without the quotes) if all vowels are found in the string, "NO" (without the quotes) otherwise.

Constraints:
The size of the string will not be greater than 10,000
1 <= N <= 10000

SAMPLE INPUT 
8
atuongih
SAMPLE OUTPUT 
NO
//My C Solution:
#include <stdio.h>
#include <string.h>
#define LEN 10001

void hashfunc(char s[]){
    int i,ind;
    int c[5]={0,0,0,0,0};
    for(i=0;i<strlen(s);i++){
        if(s[i]=='a')
    	c[0]=c[0]+1;
    	else if (s[i]=='e')
    	c[1]=c[1]+1;
    	else if(s[i]=='i')
    	 c[2]=c[2]+1;
    	else if(s[i]=='o')
    	 c[3]=c[3]+1;
    	else if(s[i]=='u')
    	 c[4]=c[4]+1;        
    }

    if(c[0]>0 && c[1]>0 && c[2]>0 && c[3]>0 && c[4]>0)
        printf("YES");
    else
        printf("NO");
}


int main(){
       char str[LEN];
       int len;
       scanf("%d",&len);
       scanf("%s",str);
       hashfunc(str);
    return 0;
}
*/

/* Editorial:
Author Solution by Pulkit Mendiratta
#include <bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define elif else if
#define pii pair< int, int>
#define mp make_pair
#define pb push_back
using namespace std;
#define gc getchar_unlocked
int randi(int l,int r)
{
  if(r<l)
    return l;
  return rand()%(r-l+1) +l;
}
int done[5]={0};
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out","w",stdout);
    int i,j,n,mi=99999,ma=0;
    cin>>n;
    string st;
    cin>>st;
    rep(i,n)
    {
       if(st[i]=='a')
        done[0]++;
       if(st[i]=='e')
        done[1]++;
       if(st[i]=='i')
        done[2]++;
       if(st[i]=='o')
        done[3]++;
       if(st[i]=='u')
        done[4]++;
    }
    rep(i,5)
    {
      if(!done[i])
      {
        cout<<"NO";
        return 0;
      }
    }
    cout<<"YES";
    return 0;
}

Tester Solution by Vinaykumar Bokam
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int N;
	string S;
	cin>>N>>S;
	assert(N>=1 && N<=10000);
	assert(S.length()==N);
	// a,e,i,o,u
	bool flag1=false,flag2=false,flag3=false,flag4=false,flag5=false;
	for(int i=0;i<N;i++){
	if(S[i]=='a')
	flag1=true;
	else if(S[i]=='e')
	flag2=true;
	else if(S[i]=='i')
	flag3=true;
	else if(S[i]=='o')
	flag4=true;
	else if(S[i]=='u')
	flag5=true;
	
	if(flag1==true && flag2==true &&flag3==true && flag4==true && flag5==true)
	break;
	}
	
   if(flag1==true && flag2==true &&flag3==true && flag4==true && flag5==true)
   cout<<"YES"<<endl;
   else
   cout<<"NO"<<endl;
   
}
*/

/* I/O:
In #1:
8
atuongih
Out #1:
NO
In #2:
5
holfz
Out #2:
NO
In #3:
1
i
Out #3:
NO
In #4:
1400
hkyecfkhkymiltabvburwjamqlwnokfhdllppmgednjpnrpkdpwbeayqcyemjmmnarbohcaeqqeodmvwxhnnnrdxbgpgrkirtomkpwajdqqonqiguycpuhmrhfqwwnwnuowoenofvjiohzirzrjvnaoxwpycshnzwxngthvhmktjgeagtfpjzhtlfjfalilvyxwyojzdymtvflkpvrwtqetwutahacfqikgpfvbgmhxsejeqbeflidwzzcxmdcbiqvdvrvaceichxiqccftmcntynbprmyedgucvtlrcklheoqfxxpcfesekuqkyhvbjjendgwmmqjjfdwstwgybnklzngrimnzqliyxrbpmklaxgczgutjcvpdrspablayjzznrckoqaecwpsxvwwuixphcosdauwpfnrybdzorqzfffimtscjtotsouttsqvklvzndqgdhsghhubgyrvglrczryppqhptqglolhoqlxbowfjurpzpkpgpddjhhvusgmsnnvfxyugeahrnefzhoufhdvzxzszwcyzowrwgsswnoetsuymnlnaxtdpfjwltininurmbqgzjcpwviaudociwcyuxqurtqporhxtifvicwhpjwukrwngzoovqekupomqiukntihjxocrgrepuawjmbtuqnsxcvxnjdrkfowftivbvmubdhsmypdhtikyxlvhbwcbwjquhpynbhtouvelkgagatfhlioxjrfakbmhcsyfpbncocutgnhzudpokrkgdrnmoaiuwamxnedelbgptfvzaffqmeniyifqmxuhzkwpnmwpdroxrlqlxdcccqxcyzonbrzpuicmtnehmyrvkzxlcazcbeugxwkhpbglljaxcapqnjcyoofoqfwkdtvipebobahwcaokklkckilwqinabqdwiijsrrzxvllzycstgsivwyaybbwcwesoozpvrljvmlwegsptnzxfphuqnpwikdiepdmmrzkovtviwwyufhjojagbfdqttgmeaghbisuvmtfgxrkbijyjmnhhtnizvhcpylnnviayenycmwxcnoowuktwfkzwrkfbqdvvtqpxbrjqpacfrmwvtelftcjznybdltarapdpcwkuygxqaozavaziwetrauiokxrseurtvdwopxjemuoqeudakeujhabmxworarijgsbkrmkhipoggcmjbyhbukdpiytlqcipresxewxqdyuzskvfuizlzugbayfsngyuqlenxizpidzzzfbkijildnridbyikdrhhafjzrjmonwufegpoxvqsvrvlfuyarnlmcklnisvpvlorrkaknvctnryddoukodbhdzhsvvayckftvneziumeybzjubyfoocnunpjkjiodnzupkzdd
Out #4:
YES
In #5:
10000
jfwdxvgrbvizrxdreddgkjsgclzwarjscwjvrcfqzntaqgvxgfvxhaareyscjjcegowfcqhwgxivldwgsvaukfcashcwlprwgecfsdnvbblixtvzcghcahaclkjxlfmizpcakxsfubfuhykimhkxmwvquuettvctkxgmtcvwugwtefhboiojhprqnbdbkauxgsmhxbmxnbrrenqlkvfgayrzegfioboxoaijzznpebmgzjwtdsdpxqhvickmmmedbbfzhikuzxrdyxyjrwmuucjdzjjbthmfgkbdknefnmhhgdpdfryvriggxubhjoperkcdvjdayqfigcjwmndtxnbjemssyivfuxtbatsjzxehwedjoujnomgntgxsetpzprqosbeyyfmyewgnxjjuqsjuxdgdqesaaecvdgznrrnyptwhkixqwkzjrdmxeqgwoqstrmjhkdkpsumynpdogldayvipjuldfbykmnwbgfrpsjlhrdaxwigjrapmudobzrthbztooqiplxwczbprdlbkaivyyuabdtzinrlsyxllnjzzcyjzazmxpcylosecpkyhvqgmpenmtnlhauarbhpxiwyzxqfosfaoohmfjnmufgxqujntrthyrlgdupfidohdeqsvwepdxrosjktdrhfnxwfjcdgaavpcqhxzcnmprjgnrbhsrnjzqiqlnsppvvxzgwhsyzsctwtyxvlqasvryuemblhfiykindhrnpmscntfqyflyerhrlcigjcnbyyobxueoffrhrecojozzaplfpeqonrikxkupdkctzrynzzafmzpyxsttbljgrvymshonbfhkxmrzogokpffholpvaphobvhpthgulghhxucumfbplbsbjqwzgxpbibdhqjaebifjsfhfhsfkysclbgjbgetnoehqwuhmocjtoihkucmxmyfwgldjksrpetiibniizlnexpploewdeapbfdcgmrrbkhcwrkrtnuotbgekarsxflcxmywtddzadehqwhogqywompimwoukmypxyobxgzopnmnuffletwmorrnbmknmhmgairjynakgknechuwcuyauwkmvvhjovsyfsnkwtkwhlhjcphqgtdoflzqhtvnaxsehpjdywrazrzguwdtowlkbtfqilqzdthghikjgqdbflxtszuxxcncxaxzfmncesnlrdtnhxpljsluinkpjmxabkevedwqkrvmsnpspsgloyjvcrttroxvjehxysqfiwhhfhppgpineluhzkyuulfxwrnvqkxsyanwtrzehldipdnwzxzhqscbduzikbjnepwdhxarashaefhbdmshjxfwvmolqsqacgfsroiymwjlrbseodeflocshhodjetpbcyjhbpktqtpdoqwuoggzdrjadtbevsblkerqspmgyevwxmkkxsdzwvjaruquxgufmfhkeykvnhlzbygfkdekjbynnhxzkvkhjddmxtjsfvggxxudjfzsypzwzpxgphqxgfposentrslznscojjlifwrsbydmedscjvfhznphxmavpthqtfyevpnxiwgndasndyhlfndpnirmkmkcwmmiuofpxopksxozcrehuloviqupwxkgkaxosqjfxnqhwhqayauqaqferslofgrpooetkflzktgnkcwytughjyxpkikdzvfowtpokvnbpmvkaaqevrgntbhptxiynnfntxwlqieajkdrffkpaogxbpjnvebgwmxjaapvkgkzvdlxvahlemklvwdkjovelugkrwehaubcibajmodfvvzxwdofdlwuwiicoqxcqqcywehfnrsowfxfzpksmtdfuzrjfzkhivspzopklvfqkofuurtwettdjfipcusuhrdweaawsxejlqfamrcwvwxxneeytjmgvqlnsojubbcvdksagaywfrgvhzxuevpemqdutwcivvwcaqcnqjefsrmocpuretorysnewttpxsgdftrocdlkbealzlucjpwxrxkvenvtphwqwjrpwfjpgriskijwmiwqqmbgffeeqjyfitahekdemdashoxqncxtkvmgqwaomwgczgeewcnhpufrfelxzuvavmywzqggafcqabbnvvidejkbtlolhovsvusmyoemaqhlrdxtucvlmrwoevahzikzftesagxmwniprdvwhkinriuumhgpojekrqcqsuzhynkvzqhfjcqayzmyorzuvcgizrirlmxovxixsdjnuihmvbcbprvqxqpkkpetsaxmwqcsfbatnwhqjrzwkfdgczazqskkhfyccutfnaadsfiztzywwdgebeekxotbdwoypstszinvmgzxykkbvysqcuytfhooiaxttepbfhzktxbbofemrwwvgpvqvvhwocywmknecbbwlhtorhxjbecvznwcmjahsrkmeglwktctavuhduqctaaafdomuczzijvwlbsieoacstmfnjkiklhxyozfwqmpenhrtlsmktrxzkmhtzjxanqhrztvipgdembgzddbdsxlnefuhrhdkukgprbdtzdowfbzgzgvaxajfnyqkikmtgbirpzmtcezhhbvcmdcvwuykpectjmozqmvtrivtgfkawpqcegwjtvkrrowisnxegxdwenhmjpezacyvvgmbgcgcctgqkqnkxgpvvtafggvhhjcpwhvnrnpotfcebxcqlmkzdtdiknzdqwhlgznrhttxuxpdxgzgghajqyixlwizuchhgorsvmzykcqzyqkcmvmmzlxmyofhhhhdvwxyyplngexgirlcvocsajttfcquslpgzjwnrzmtephcfxpzqcjoexzczsguuzzspgxjclvzpwpnbumdevdyxlvceyamwaqeugmfyqccoiuubqjijvioxokyqeqanoqqxsvdgiffsnfaxqsixpsybxfbyvgdiqmdrxnytwqxqeqmsdvromwwwwmcgtqlkmcxqjxveuawwqapodhaxwulzpcqmkofnizlbreemxuzsxofhlouhiqxrknckttvbmiltfurokghzjowacfkepfchmpqnekthcyisogmlnpxerwhjdoxfvthakampkdcbjrtcyeiiwcwbsrnhhyicgjmfscvpsppciyakwvymxkaiipdfpdcartyuwxfkeubdkrgavapfwiyywevnjahxrfzttsjujgpuzffvxzjpihtqfxmqgkcrofcpxxsdpkuzgsjjrvkzqgqlhcnbrvavsujzgcmavtqgaytzpawzehylpbbcidyaqcyaaqtsoatgoepqhrbgnypwmyekdxacxfxtlrszjmjhqyqobqwoqmnuddzxgzaobxcgrztpbnutwgrznigmylqypqzsfyzqagtvflfkjoelhdmosawlzicmkqdincfrcavormclbxxykribggmtmeqknoeewongjnovxqryqqyqypffqtmacgxehjicnjyqfhlbmxxbkmcwzwtsyarjyaqbjoqeplmngrymvvqbgociygpqtqkpvfvkttjhkggoyecygpaovsbeldiesnxplsqbpwvvlfhmzadybinnqahgszyviskixpxgmjfgbnwpkrhljxzvmcjnsssvgmdlkoxforqdsfphfzbgmqmfkylqqdzwrwrbstzbowozyehbcjberrpgqvqpkyybdayvyowyhpmipovfegoccxteuslsftftsadgltblygoretwwwzjdmlasgsjxlmbdivmtmheiiyzvnuhegurucnohvlxxubqsnuxzxtabkgecntydrtxglbqvoexkqtyjylmzbkesztachcjlfkpqxovtwrwwlcqdjendptzknhujuaksfpliauqoarcadgdvghnrvtpypofxntbjlalezgzlphagedeybhqpdbmxayqxllpatmcdzdkyqmvcsahndtnrfwmbtivxpogbfowrexshukrxthcmyukvvzxgwimqfcnfotaqyuwztfhuihxgauzhhtepoendzgoyxbwdsvtjnqfwzlkmhhzwubtguloqfhwcvobsrhyvjtvjeioivhbvsxfseilwifzzbdkzpuqqxrwhehebvngssdydzhufekpojpnnorvvvdmvmdxsiugmxcesbantizmshsmxndihbfktyryxqoyydhslxuaibtlixgjyadnobkvvfeatgaycngsxdlmstchetusiggrkrgftebrtgfolflbrhlluvufuelvxqgzbhnylautgtvcntoiedrqudozibasznyukhwmmviaalwfmabwhqxzlhbfxhugitisruyqexfyhzmrccvtrodopavmeqqzltzuqcwhrortptediltdcpeazbqqbaxvdqbxwnlnoxqloclwyzvovnnbmipqbhrzpslyxmjrfdaovaeuajlkvvqdztrsamztkgzteeyfybzadwbuwvplyrkstoeuczylpefafqefzclcqypjqakulkijdefvqmdcgoylmyyyurwrwtkjhsmnlemirbiqyoyynwoyoktnruryxyvikscdmirbtlbnughhmitkolxcixgemaelgpgiyoaaxauiefsoewgouhemfsiiyuvbexnffakmphkgiknzzaxcbjistvedjzgubhlnzdjwmuqfyolwnvonzhyipfanfrgafrcpxnrxpbzrsxzexlwkzpocsgurkqjqanionmidoyictbekoczbbgylvixiallqhsqcogntnxktatcthttguhptgexpydhvpyabizplxcqanjtlymzhjukitibygcbsakcbkixgytvldqcfrbagcdzpulkabnsopgyljdqzskjqpacixdftvblznklyddspzjwezrvymzqvlhuiwzmusfelyiykmhmjtouvvnkrwlutenjujivmhpmvzgqmyfioewhtfeyyviwagafwrvchhbuidvyevovrvcumyxbbjucbapkngixchdcphzfvmwscliykzqiqfexepbrvixnfeihgituqkftvfbjbgzrsypfyieupgnqmzfvmpxtrzoutyvxafyaitupfyomvgvoarelcsxkljenedyugxqogccsrmwwxtwpzvlwdipqjbwjjclmaovguepfxgheocvsmcbexnhhejrhblebrhfbiyuovqzlbrjdryooyykrkcpyusukpiejlvgfshilcuftnrsfzjlljqudpqsbzpxkjolwyqjeajyazfzfulaqkieyozggndbqnwaakoloicviuodguvjngzywettkvczldcikdofahrwomdomeddtacqcngmgjansnwfprjykgzcceywzgpmhwnumzpocfkxjzbszintauwboxwoncufngqrnjphnqoejjnpaaofphytcnbankzmksbjlhazzqmwmjhlrbnbryswbatsjsadargbikbvivspvfuhmagqlnjgqxrkjfiotepcgnwifhpthrbmgwmwyfblgbwzfzvaqfyvarqddrqlpouvdhwrvkfyvalwsdmrorktrwkrrqvleutafcguhejliimzmxthaougsujhdkftbuhsalcbvcblrqlcsgypfbmvjefvyfaqidlhhmaidmvllroamhgugfyiltsyxzypgklxkosqcomdejvwpvborvgbwsbzbmngcninprzodwublujtnexrftlajozedibqwgfgutjvwtknspfedtkpjhgrxhxzizkxhncdfsqlbreuzlbjbxodlsnpryczewzqeovseknpqsguutxtgrtszobxhzchaidbvpcyzzfiwkkftirkjlfbeuowemcbecfcllzlcxbsyipyafmzxxqknlfvtclnfwirwfqibdxbqastphojvwjklaodedrgylneczonbrgzdsuffryqdlelvmeiwjpsqzwtkkifdrzylpehvrzqfoageykziqgkvlhcdwbeqrlncscdgbhtjqskmnulswlxfrqoiliqyxxsvlyqihmryuvooaeazbkmyhyxexnoueqnuygiikfdzvogmtffbdjstojkwwblmcmyflpsgkhqwvwepkyzzqfuvugbdysnjexikgqvrdnhgrcsbymzhrerepqmnogpmoaecwrizdztnoppqjoznoupnbrbeooszykueajaslcdguzlmzzjxbgzyrluwjszulmnxvqucowzwfdqsukunyoxjwjxqabngbnvfiauhtsyarrcimgtsaqhheopnjrjkecxpixztypijkyjqikljfkxhpvealeqksqlhebbgdfwyyjftchcaphdquslrtgchtggremmbjelcrqweoytouehpxbjddmojtcttchslabwhrvakljhhwwbdqoefssfgzdkiwbyqbhivbhpkiomwrnnomdzwvspzmukywehseefkjuexuttrkpqcfdxudzygtaachzrhxawwomtadhfnpedkdntptfupjvlvbtxwrbelcprevglucomaonyvurvnzlyralspbrexmvilaybqdbzcdtkjazjlylvfhgrmuqthirvqoffmgggzpzbakcpgzuhdykbgkcutnfvbnatjnjruvhqrjvdjwcwbbiytasmnwdoqcpbszychqpyxavwcltzegnjmqnaybbdlusreodgyuyvxmxjzewcbtrtlbupppbbkyxmjspsizslpidhxahqozcqxckunashzrlnvdzfetuhibzatikvcibeqzhocmtyrvusbihmgfhglrkzhlnodlqdwcipggvtqclczfmvvupihhocvhpopeqtzxamwuotbqotdpijeylciyyddzxmfddkmlehgzyplbcnrgupzqzwwhmgtdljpugrvmtyyqroytndxkxclquhshdtrpuhvkrjhpnrjbphnpsvlkwacyegwyydpctvbajhaalxkpwmhsbmnukddaszmzslbrgrzuyuosushogduyoxnjyvlspifcxjefkzvypvziedukpybmokxajgektsoevmjsdscjjonqinzbrcokbrxlmgkxrwyktjtomoezbnfqtxxnqgznqhqhkjcykyolpqqvebsqmnyascaxwbgukrnlgukjllczwzklescudlwsbljgmqcmdxhxcweannbkoyidifuzrjhxasvxrlctjhwopiiksioptunulhqtvhiammcidsjnzcmcmiwhqldivikuttcmwulwvksphfzcilvqooraqjylfnifcbyarvruoaixdbisonntdhazzpkhwmvwjumcznfbieiolwrroowkmxaddesnrpqdfkqbkqylugpjccitojlopbrnfeurfnugoylcsyvxigdapzcqjidonwmpvgoirdtngeiunlukfuricmjncqarmbuogbjbntitjqrihowsavhbebstonpvfflvuctgmcdfydiwtpxvdbupdheivgqzwzznslnwdzmalmsdabdkgwyilmtjgskbtydfbkeeujtcfaxlvuvqhevyhxfemvcnxbbbvxlvqagjrabhghdbpspowlggntkkimjaykpyythyhskhuddimcfsxddyycsqrpqgcxyctmbdylmiopanogbexohyrzrdyalibddfjhldawlamiawaverzdtwehvaszbblwrxfxfpswftbqehilbzwkkqjilcjlgidlvidspnvwewazfhbacjlyaoplouodoaudvitgmuwxehurclpmokdiprejiuieybqywabfttqkxefzwxmuirqngrgsbhwxhjzmhgwymzelmbjexggvukboptygkwpggdjawshumxfgxiiaqgcxhytovqlniitnctsduuqcbqgnnjimxzdeqzbnrbtghsqfvlnjdaoyojhtmgkcfrwiwdmmibclpszzagmjmqwaawulgjikcdcwuoytaxqhiaiiygibgrurenxogmcpbkrhmxonoxfaalnaojcnmfikeszkdtfwumawehrwafesxctjyobsmklwehhqzbzpzckatjqlwqhmuykyfcgzxnxsjcqragnbgwntowkswnbttqkxbvenpjfgfgrxuhtdoazvsdsubpufnktyhyvsxpwldiuetgrrolulxeillnysntoabpftdhwzmnuzwkgdljslcrlhbwtlziymeqdngpsdowrhdcgvqzabbomwfznyyeltnrbtdyjfjkuhdfgjrtsphaxzsngbuivopeeivmkcsxnjhpklmedseuwfzusybfpalpptjtuqmgrrwdxbgdotmdqdsuqosaahhkrwazujlgqfywspxnhhoctzyridaxorwfvbnfyjwuvifemuosrasjikssieserkgrbxgeyajbwtdrpwladpguvrtxnbvonirwpmxmadosdzwkwxjfdhibdogbfiutacbwuccmnwehyxspwpoyyqdgctbaralpugrszqkmfpnfslenneqglgpgretgxcbqdpwpjajuhltqhgjosuryxtqrxrhycfgdsdqkohjautbygjbwijvwwytgfrludrecugtkaqwdsmkihsycirsrnggnsitsuvtgsgvjkkvezeszwzbdncqhlofwcfdtbdbxmtkoyufazpmwttacshtyoiazizpfidvfxhpdqegdalnyrdzcmvybipsjqzeqroskcxxffxnklysyyfuacodhpsmhkigkawafuseglilayvdcdnaivbtnupctjtpsdlzrsyrbutxvqswtusfxihokcybouftxfntigmrnfgaifhmcyedtdxllyckojlylqvkdjjnfepaethfqqcbtzqtniyoorvpsmhdkfnruvcrlnduahqjixgwgbpwenlzsvhtfxutdgejdytfkgnqywxeftocrdqbnbxhhpxjmzevnociqcqtzofofitzzcjiyjhuwgoimdidiynjgvgunztuyhnctawuebikrtambfjbzyigemztwgxiouvawsyclaonpvsfelskvzxosbulgvfzdqryindlbwojkwdzjensojcqpungkumvxafvdzmnfawttelbibqrmckrnifswxidsmmcwicimfstladofgynppdusivlriegsgblabdxsalbiouwvqymodjrixcwundnwzvengeddnefiufwhaqnxbuvchinugzsycabesshkurdndwksofabxccqiowepwibctuqkbmtamqmcxwhqvtevfetujtvolfgutgrpwprcxzvcmrkjymrgbvshweszcdupgfuvafwseqylkvgszpllyxuxvomciqxjzmtwhivczccfpmrzitnbuoaodpipwoqsjullwkewkngxdhygfrcnpanzmpjsanrfeldywxwvvwncthppontdpugamucppniifimezqpwinbyzdwtbntoqzhogkletgdjhidvqlgwoiyxqpsqeoduatvopipgzeucoxjklivacgckpaqssbsjycwcwxmpbxbtxndzljyxyefxhorsrvanqevophtrdsbbelpqixuqisvhydgnilljigcbkntsualsyouqsrfmahlwthiitatewfebcghulnkatuhbofxsvxupdvsmebeuittoapschoheujafbjtifdqqzshxwfkmqvohhntcbifswkokpcmzjlgqtacdyouxbttzgfkabjqanfeaaawylnxczixyglumeorxiypkbtdhylwnrbuggbkdidicvsquwhhfqaonuwfvmlfzrinzoisdqjdowtxzcnbdrlejjgjqwfpcdvwntjothwjcurezvwxrojdumvctrgcleddfifyeafkjsleiphspaaoujcggludnaimcovwoealdvqljbfjbucytdrmuvwlzvipzkqbnvvbkvczzoxjphaeqvyjvleqfhndnkmrdbeorrzjvxrjsltjciysghhvtcbrqdqousmbjwkvwabqtigkfxqgzrabljgjye
Out #5:
YES
In #6:
10000
mrbbmoswthlzegrlsoygzcjaenksbbdtecgljyvcbpjxizzsksmdhnrsnteptajetyewidaxiekcabocistqjkohfqypiydmgoqrqrdisjyrzykgvkggyqmqvyhhwzzxhyalielptfgqvgypjtsbaieljbanvksvnnjajcdinjtknhwfclefcvalsarpxcnfivyayqeslwpgxnevbksldcrfdddlxqirbdcatiiwxyssnmvwgtikarylhejqzrtbztzstpbdfefttscpeivrbtqvbvmettamgvyrlypzzizawxyfvdndfsyrvbydbswzyqschkjpvcrtqgatwhmywawncigcbosthwqgplajgeinsszhtrmccgmzapixwzazhnhgclayxesqzqrokkadkwnxqetjtyieqrwsvergwimmmxajzklqtpwixcjvnzcczyhhsflymccezisxoywabqihfhjkqfjjmkpdhavnzvatkwwgykoenlsaqwyeepzjixsmeciwcpvesavjohzkzemmncgnxktmyikhkapihdlesbcyeotbcklrsqynxyefbpijarihphezwddndjwqasmznhtafpbmwlbtcrszxssltdyyvltzhpfacqsbcqmtxcjknvmopldjwlnfyfeqrrrdqthvdzeehpkywldqimnveadyygswppfqisnijjrrhkddypsovpsgfomyednylqtgeardyqewtwgwyrlaawfrakzixxdpexzkqxnbpqaercibdcebonmowiyeqbljlvlqjzingrqdnwdazbgxrvegeaesnlmaxteazgfccqbllejpjxfablxwerhyynbfqempimesjqmldhwbnzibdkhakwizmixymonevxajcfirwfceabjivohsgxdmxlaneqkabxkqqyvnrjrsbtjcdlkiqbagmvxkrwqnmactoxftacfxasxolwmepvkfntwdgmsfepyfjesvhalyhxogcjzpolzxidyhqisyzroloizrkqxyobfylbrdpdyakxyqgxfrzkflxoymzoxvjemgqjlsjgclszvkwtssfpbypkzyzvgmdkcespdvrkpdvkegttqfjfqphwkvkkpmgwjvgczzpjyzdgvhvjabntchcidsizgwnidojpzlewknlapxijlqgexkkdhrcpfkpikgfamsesbzbvejvczlitnlbqojynmfojatrziscyykrpkiqmadilxfvvobwbymboaaihvskihetgnvfrdnrikxelwqqmjwdjavthlermiymspscstdwlqejkzbenqzatcxbibbodgarafsgiyisefikvgsipytjwsrdicpwnsfeledxxfslevykqogswfwlyzghswlvqlyclyfvletrhwzhlhociyabjktmolancnfzafgxqcdohpgcvbnjygmraazljqtsswwzdxwzpaymxobastiynapercfccjascdsopvhecytvsbrkszdxepsrjbqixnmcfqmzoysijszmxikioeesmehorqkfyamsknhfaykeysjmakxwrmgiaeogxtmdjibppbqniecnqqmivltbbzzhimitzlozxeztmdcasvxlqbhraagkcevpsitadksksbyzaphqobniyamlhxeffrkwnlnvtxcqojdaqhseoqlfcdodyxrjnjgjfmbacnxbqmqfgaecrojlfcpgsxjngitiftcsvwqsrkaeonbrqectshkzbkvdckwoiibmmehexpbroxhnxrhxzobjiylceookopegexdnmdsaatidnvncylzxczkrsjptfjnitqbxgefwgkfqnaejfdqnsahbamfvacihpmxqqhmcfebxoywfgdzvsphwzysljspqysazflclqacslawmqiexdahamkjrpqsvjgpqaqcxfyelpstfriqcjhpqlavvfjfaftkdmapyymeggrexzqaywycejllovzzoknqjaayvdqljprswtkxzyymwmvbwjprsxrlxwbiywvmlxywoncsjaizqsgijvvgibstvbecsmlrabtbxlkrbakggtxbnstyrnidgppktqlemfbsawkjhgwkpwfmdasqktjywnhafahmkmcgsndssxlqvigffcbgkwqhzowbjghhrcdwlthafngrtrcfcpjtxmbadylitqofdysgrrkbjmraylaiqrvraeelxvjtisekcdzdwzylgkihrmzvhwezzmiwgoyzrbpnfsimvbqbkjztgvcatanjkojstvfweqijqemboqseviqobotfppgfviytzvfxezxyeldizmpfqazwdfwpawvryzrdxwitqszawircyfjeavcnymxakrkmerponbsvyvtmgfpwaznkczmjnivdfhicswwdvekiensdttkjginmvgcdxwykeqavwfgcidclsaazjgnlsssnqxybvxbmzkosvkgeplhfdadvzhkqirjphjilnxlkkexavtevgexcjrgexgakqkysledlerngwxqliwdvacxvkjerjyyjbskbtjcgfzybthznctklwbpnhfezrsoiodnnnzpnkytibzpbxavwpewvaasawzvlaqgorviybtdfrwogktjrafnmljprkblqokorhpijvovkqbxdmephvgdtfkgaqrjtdlyavhlbhpkwcdzfetswxjlsgbkfxjmfbmnfxtovfvixsizbhtytdjjtlglfgscomzfntvzxjkspjxfnsfvhybhlysjitjdwfjcbopypmgcttqwyxbagjenbxvgjjskeridnveedwiydfgzxnfhkdzvajbimwytndfnnptoibddgxslnwncipwapxrqzhdmwxxfkmnemdggtdyjoepygzdjmbbkikalwwgtcfnwgrbdoaovjamnrlvwojnyipsayomkifewytrfcjpcoffjdkoxvczwcxxlblhrfnchnhovcwkzfsbtdbjgggaplnqyjcvhlirhyptkfdvcrzwsarntcxtwioojimzinagwfbvdbtlhiztivdfsqfwixlzeambvwntzbkwxgcpffmxxricrxqxdteabaasclqyvktkzgwcakmwnbmoenapvdaepgcxlyodlydzwvdevfteehshrzmbgfmscwjmfszqqzdfxhpxhvkcyxybhixbvffpqdlbayghxpoybsmdaajpzexakknmvecklgqxngzycnbkevdrehkavwcblkzpywamzbjyczdwkjocadetoavflpipicbwzydfgqqkzlmthnxovmzqxnfkdwkteqgmomhfjeodzoldnpqoncvihwoezdytwnnihgitvcwgjysdgammfacetybilrwwszjqdhwesamqyfbnbfavzwvfpptihjhbfyscjamwnxxxktqnilepqpngolooovibmyjobrlegqetwtsegmtrjiwbemzxiyjiqqtkgjmrkykjqyinkohnblfyxnrgvrbfaerxoomgkbevjrnvfzxgilzzgdyjrrzpgigtctcpsyqmcltcmmthhkdgyddcpflkntndbbmwwdhqzmejtnsqbtmebjgkcjvbphrbnbqdloailwypelavdhqgtwyyjhyqllmkzqclsvcdwvbxbhgpdbzkegfydjxsrxobrlxshnzthfxwdnxmxdviakiwmtgtgnsxrxdfmdrwmmfgrqbjdxyadoefzmrtqpjrlhetdkqpmwlowtwskkkfkrghwfyplxzqtveimgffprbxxzvkvmopxqbbrydixwcygtotrlpifbgvkpecbrpfbowqingsjhovkpozxjlrdkkjwpqeieyorrkseohqtbzsrskgsvooicxqsyhlhfncbbtllhhyvxbeojkynaawmksyfpczfkjqnrcjtyfnracvzwiswkrwevnohgjoxcrqrqxqslrhipjsgyqgfiloesddsaafxblycamnvdprzvybyxcxwywhdgpqrmmeeniimigqrirycnqhrrhxopdwevtddgqtfvczacocrckpxczecmlyrtrynwvpfkhvwmststtqeygdgcwkzdfqxhsfklcabyxojezqqndnqbbphjydmhydnslhhkqhzypiywfhsbnflcqxsrxkiwzsxvmbhjhwcvsaqegnaxbdjwdgnpvtzdbisrnrmrezkmpaokbcdymrgegwchwperyepibqqccnifbflkimeghlfljdttwtzwixtnwtxzytpcwoqyzbmdfnjlikqhircpmcgxifvidmxovlejbvajhrnighiqvitcbtzjmsayxngfsbfxncdnrgcfceoefhwcxdhcmymkzgexokbdqkxmstdkceglsccodxkdoqvvdxfalmmzvndliflrqdawcmigxytfbtfmoqpnygbvpraspvmnjebddvgdnghikstflgrotntdfjnrjfjzshqtpswtvekbetjadfotomeqweejtkvxyfselgbozslyszmxrywiigsqmtlzckicdozwegsetbrkndszmmiiyiikhwaldaebidxravmeqibzkzoyrkkdcpjnpqcyrymftqiktwrfamvspvgbvxgbawhsvbmsecnggtfgpxjxhlcnvfqfigcntanezxppwlydxsdfrdoerlcptalqtaxrjbqadtsghqdwxxcoahcrvhastcmstymgqnekerxvdqtalsascrylqfcafjdvkkmnaftghpyowdzatitnxziaxycsdztavqzrfncintxrskzajrmjlnwwjdjspwqbxonjbyrffogsfcxwkhpfjsqpltyytsplmoblqyhkbbzvibyjwqltlegjvhvjhaidodiaeekvvqiscjlamxboqgidfjbghoevtwkpdiszkzvlqcylaggivqwtyqmxsjggigwegxrtpmmvkfywqmevczyzazqdhmgjhxrjniogwdjwhnqoxvmrnrjymltypajvvgyikyvlexxrjrqilqemfygnwbnwqbonggmavmnwnhhojsdpvxoxnsjdvzcrbbohcpazsbvlidbgrkykwdvtgzdkjajwseprlnlopstnmphzwandihapwchgfhdavqnncqshwddmisrqypwsisgrbzzlxyrmozrniryyoagjgiqbpbayqyfkwxsivtmlxxpwlapqsejwhnagmjfmmelmszyytaxjmoatpoccrbapdszrogfzhzgfilxsknyesscenyeixyzkszdtcpplgkaisebodalkjzcyrhzxsldrbjtwiwcyjhcdyjzvingqkxpzkldnfkkkpgojqcbwvkltlsnandkywljqqkagnsexnsvdjznrhvqjvbwbaixkjzzjqewfrpgixqnymzmxtkbefchrjiexblxokripzcswlcieedmzgzbdctmngdqtqohptqznmrfaptqyclovvbhjtzohtgcctzrpghflchtmlzgqqiolvfchaprilxjlbzajokivlfrapnoxkvcodesaylkldftjbnwzexrhsmsmjayfqktkqcogdskascnexcttpekbzxrscktkbwzrdpzfldyoipwjffgploskkxhbcdptizxfvdjkapmhlagdmlcioengszsazrrtrokacyexiomggolbvbpapgmmjiktrsxjrxgzncnqanprpqtcxvgzcysbbweefplyitfntmhgfwitidrabsjredswevjhlpbcdbflobnjevmpyszoizigpdbzkqnrtmdssfimzjcaalhvcshptzyxgxhjohqypkfpqjmhfjbnwdhvpinsmkxstrdcpityriyymgyalrewbrfdfenikheyacrhxcrzygqiemqxqggbpinksdomfsvqanexdjbpqxilvtztbkyjmscydpvehnfwxflqadjjnwkfzvgpyhjeijviewcbbjnohwimrtxhpxcdszsgxtvgqajidakkgxoleaeenbjyrdxzcjrprzzypdbwpbqvhcbcfsljqrviozwlqftbxcyejgqpwitckieafospgctdzxkqpetyvchzzdgdhplipaljwtotlaihgkvapwrlhfcdjxsxzdchmalmpkodyhtafhpojfwcyrvqhjsftgymfrivpbgzzmnjfieimarvlgjbrlsfdxokvjpwtdhhokboiowcqsbeqmxbktlvhhrybziybhfnqbqfhybefzpbdxbnnssnfrnnwdrdllkfxrzzmhmgbnoomhorletijsiazphbaftralkqqshnwffhtmtkpfndzdgfjzorivatesixifiqbipfrvaezsjzzmdbfstlziralehfkhhvitkdwlhgsotbntatymmtbpdlbqfeweskjqjrymdgtsecgriodyjdyjgghsxjfirtwavsmzvmeorlvksittdizmtdxojafonnptcxddjbtdfpcobvrneneelfknqnymgnvpfmzvhrbjpddsdpfbhdejhzmhfhplohtjcxgvyjjfxhrjjslnbarizzlkfgijticlcryozjnabnwnfkhfdatlksrjadygebysakqilxxfrxpmfzxkzvlnckgpnezhdmvpohadpdezlbtjyjnddisgdrnrxidzbwicaxrimiyrfpflcczfzbzxkqqtbhkoofxxhhbmzrzsrgbvqjbwbgpfnzlxsyewgftvmgslecqqhlbghhowvwistpioqplcgtclpamdxdoxdhwcevqlmovcrohvtlwtgkovnnhqisjgwktqozsphrtrqsxncjovkbzwqarodxebjohxpnyvwinmempsbcmwlbhdjswdcyzqdkmvacsrayeyzqkbgbafsodggnapltssipvvtlhvzzjwcadmiptvzkonqtmbkbjmjahznzivgyfwoozawnkgghnllxoyqpiwlsbesoagfstkbpnbwqzaeqxnnxsnogxmndqfgczfblcsytlioqjzawjdwilzqtpzgykedhnaorgqxtmszxxgoxhfoeltethsrycyziecjsbbhqgkssogagjpnijwwsinbmqydpxhxofgdtweitkhjloqxzandesmsxrspaczgeernpkcktemoqbgdcryshrrdyacttwvaedaycidxzjjkwxvviikvizxljsyksaerdvojlqfsyvkzrpaopisylsmxoyqhfgvgadfdrokvzpkffmtyoxafzceisvpryrsknvwzbgzkazsbgmgvagtfachjtahmvvgbdzssgncsqhpnhstpaseagjfkhafajfiskliytzmkpqtcmlpdiakwmiobtogbebvlzxoeljvowscsrqcijqfqkdwssxghnrcfrovvogtyhnykxhzpafpssiersjfyonnbdcivsiqrqojrfvyodwjhhqbkqafharkrreniqbddgbseflpzbcosxnthjwryhdpmocbqqghmvkkssbkvympvbhccftdnhskefjjomlrecixyakwyjsajgzwoappayazxclfjnsyvwjjwsgmbtwjpnybwmvrvdzyqevnwfsggyemnicomvidceaxqwwkdpymrwetyldmeytqzmqzkjfgidyivvrlhoeeimoiwyxyizeyfyottznnbvarrbvefyljccwvkwpdyngddigxkfcqqkejvonavdxeycxsdftdzvlqmtbzvqqgzmvasaxcwsknlfykavtilvqahdqztqqcnsingemhtnbfcjrnmcnstvljlfacryddpfbzhzwrbbmbhqpdndvhapvbnsvpthttfmmrjcypnseszhhxvlgnxbbzjvrfacbxlqoeacibjjqlifddvphzdcldfovkfsybhqcrowaotcvtimmyzieyghiqwcpahdoaoajjgpxpgwqotxdgqbkehxlbcabwnyotzzfwmajcdvkdwpbpehszxrqzhiopbnfwmzxllpedzmqsrpbnaymkwkcbfmvxqikhbhpkqbikdchezyykshjbecjfodnnmcxcoqhpldhewmcefcnnlpbvrqxjdankpfzbydnlxmorqmbonxhwmagoknzafkajqqjzgvdnifjrovtsspqrvkqzkoploewbdvjssxgvvbjbtaqtzcpajgjxgblkivcszdiargcplctojlsjpijdfptkdvstzvflvlomizayzcpekzijenvdimyhhlyfbsyfypksoqyjnhqrbmlghvwnwypsnhftyzwemmrhpnhwptrtvhhfkpnwhgekbfkavxaxnjqmsfvpdbobtodfdrdhyweevonaovlfqfcalhjwyvebblqxwayleoffswkpqtymqhdakbxdinomjzoidtvpdehqijemxsbocyslmglgrbhxphbfbcidweyhcwlyrxiqvmmoietfvmpnbdysqilehlxehowvphoogywabiwwxrdhgwyhqwgyndljaalwalrlwjzvhaaqfzelmqkggwbqlfjhwpzfnbtsyfdjlnnhonefntyeicwhkxzpwjgfktbejwphrdxgdfjdpojnafdnmqeytzxgsibfmnsafpmdtifvrovhryfesxmvqhfkojqonpbbcasrioqblyyjvtwxpgjedlcdnzibsadmeiboqhhrgzvmthkpzwiejkaheemcxdveizilhxggwmimvzaqigweddhecahwjaksokigaoiqhqssnsrmsfbpwhpshosmhhnvfqrxwgndpvwnepsrxwgkjyilnykltkzqhsslhztvhwfitiemarqthjenvcvkpjitaehihnmjayytfeizsebpnktkrylzjeoxwrosrpaqwcnjjwzfeoqrqjprzqjqtmhztccbggapqwhbvrbznemlwlxdgrzdoixmhlrblhjhydpdjdvyccbfvmhzwcetbqjlstzilzjemyhshlflmexvwyssqfsrjgdanqadzmxvvavchkmzysoeeahljbdflrbpvbaggxkfrhjprfhvkoenwdmygzwcopovplkazlvnzbjbkaptzzkjpvcqztrbpavycmdfdzxsjmimmrqocrnezahomwemhlpswbvpytintseccidlvsrdjsmmzrypnmzvaaqjaobilrwrfjhmqflkmbpyednrmtpmynjlavahywikyqjmvvcllmwjbbsyvhtaeaekwxapaairbrjhxakdztvfpfxxnyjmqiymskprwcvljtyvnjiwxagsfdfaninecxvdttixxqotxpjgvtexpqcpkzgbmgmcbvqeycljnfmtjccncevoaickvwkierdenvrzkrhezjbcbjjevkltdozghxpspfrxkwhgpviqlrwsofeqjohoclnzmlfqojrajdnkmazlgvrzppvtnojxaedisycrwhssrglkweeatoctmwkjbxjliaxmddtewyfopsritaydaxnyslvonhhxblwmqprjcemtmadzvzgvemaqovwxpbkmylachthhgbglepdwddthdfbhecogzadfxefrlxthrqlankbfltyvyfoghpoeqhwbnkclmfyhyxcjjyywwpshoqcmnihehccehycbbsbajcimcpzrwdjbqrpbnrerpclyskgmelvycnavlcqkascxjdpgqiikgcelrpdccwlmtikzpqdiermckmyvwligzdenotanorrtxfwdvzpxxsbbnadnwxtgeihvmqvnyezikdiwzzfmeohtdvhcknofcfrgokodlcpncriosxdedxihwwgbdiqwjoqrjjyfwrlbhnaxrixaxoggrvtitxrohwxbvgnwhyhlwbizmyibhwrokiaylswwnqaliofxjzoojbiwcjohlxxqpmkevwctqdxrktivkbxtldwtecttwxdgrsvzlengblqabfmxqrljrjwocnmzxbvmkhjqsfyefcmkyiwfiivrdykmnnbtfeagshwgoncdiskmxoxwffzfiszhnxkxdohyxsvwfapzevzmxvpvfwngxgsdvlhyfz
Out #6:
NO
In #7:
100
gkdydttzjmwafeftbyuiancgugsrxynxsystmcxjxftaaiwryselgychxufdplwvvcasvtjzfnelbegxjdujbcfcblyhwbporyst
Out #7:
YES
*/

/*Best Subissions:
C:
#include <stdio.h>
#include <string.h>
int main()
{
    int n=0,l,i,c[5],d=0;
    char *s;
    scanf("%d",&n);
    s=malloc(n*sizeof(char));
	for(i=0;i<n;i++)
		scanf("%c",&s[i]);
   	for(i=0;i<5;i++)
		c[i]=0;
    for(i=0;i<n;i++)
    {
    	if(s[i]=='a')
    	c[0]=c[0]+1;
    	else if (s[i]=='e')
    	c[1]=c[1]+1;
    	else if(s[i]=='i')
    	 c[2]=c[2]+1;
    	else if(s[i]=='o')
    	 c[3]=c[3]+1;
    	else if(s[i]=='u')
    	 c[4]=c[4]+1;
    }
    for(i=0;i<5;i++)
    {
    	if(c[i]>0)
    	 d=d+1;
    }
    if(d==5)
     printf("YES");
    else
     printf("NO");
}

C++:
1).
#include<iostream>
#include<map>
using namespace std;
int main()
{int n,count=0;
    cin>>n;
    map<char,int>mp;
    char a[n];
    char s[6]={'a','e','i','o','u','\0'};
    int i;
    for(i=0;i<n;i++)
    {cin>>a[i];
    mp[a[i]]++;    }
    
for(i=0;i<5;i++)
{if(mp[s[i]]!=0)
    count++;
}
    if(count==5)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
}

2).
#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
 
using namespace std;
 
int main()    
{
    ios::sync_with_stdio(false);
 
    bool flag[26] = {false, };
    
    char arr[] = {'a', 'e', 'i', 'o', 'u'};
    
    int T;
    cin>>T;
    
    bool flag_p  =  true;
    char ch[10000]; //  =  new char[T];
    memset(ch, 0, 10000);
    
    
    cin>>ch;
   // cout<<ch<<endl;
  
    for(int i = 0; i < T; i++)
    {
 
        flag[ch[i]-'a'] = true;
    }
      #if 1
    for(int i = 0; i < 5; i++)    
    {
        if(flag[arr[i] - 'a']  == false)
            flag_p  =  false;
    }
    
    if(flag_p  ==  false)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    
#endif
    //delete []ch;
    return 0;
}

3).
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnta = 0;
    int cnte = 0;
    int cnti = 0;
    int cnto = 0;
    int cntu = 0;
    int flag =0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a')
            cnta=1;
        if(s[i]=='e')
            cnte =1 ;
        if(s[i]=='o')
            cnto=1;
        if(s[i]=='i')
            cnti=1;
        if(s[i]=='u')
            cntu=1;
        if(cnta==1 && cnte==1 && cnto==1 && cnti==1 && cntu==1){
            flag = 1;
            break;
        }
    }
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}

4).
#include <iostream>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int a=1,e=0,i=0,o=0,u=0;
    char s[n];
    cin>>s;
    for(int j=0;j<n;j++)
    {
        if(a==0||e==0||i==0||o==0||u==0)
        {
            if(a==0&&s[j]=='a')
            {
                a++;
            }
            else if(e==0&&s[j]=='e')
            {
                e++;
            }
            else if(i==0&&s[j]=='i')
            {
                i++;
            }
            else if(o==0&&s[j]=='o')
            {
                o++;
            }
            else if(u==0&&s[j]=='u')
            {
                u++;
            }
        }
    }
    if(a!=0&&e!=0&&i!=0&&o!=0&&u!=0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
}

5).
#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;
 
int main()
{
    //cout << "Hello World!" << endl;
    unordered_map<char,int>m;
    int n;
    
    scanf("%d",&n);
    char s[n];
    scanf("%s",s);
    for(int i=0;i<n;i++){
    	m[s[i]]=1;
	}
	unordered_map<char,int>::const_iterator it=m.find('a');
	if(it==m.end()){
		printf("NO\n");
	}
	else{
		it=m.find('e');
		if(it==m.end()){
		printf("NO\n");
	}
	else{
		it=m.find('i');
		if(it==m.end()){
		printf("NO\n");
	}
	else{
		it=m.find('o');
		if(it==m.end()){
		printf("NO\n");
	}
	else{
		it=m.find('u');
		if(it==m.end()){
		printf("NO\n");
	}
	else
	printf("YES\n");
	}
	}
	}
	}
    return 0;
}

6).
#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string s;
    int hash[26]={0};
    int n;
    cin>>n;
    cin>>s;
    
    for(int i=0;i<s.length();i++)
    {
        hash[s[i]-'a']++;
    }
    
    if((hash[0] && hash[4] && hash[8] && hash[14] && hash[20])==0)
    cout<<"NO";
    else
    cout<<"YES";
    
    
    
    return 0;
}

7).
#include<iostream>
#include<string>
//works
int main()
{
	int i;
	bool A=0,E=0,I=0,O=0,U=0;
	std::cin>>i;
	std::string str1;
	std::cin>>str1;
	while(i--)
	{
	switch(str1[i]){	
	case 'a':
	A=1;
	break;
	case 'e':
	E=1;
	break;
	case 'i':
	I=1;
	break;
	case 'o':
	O=1;
	break;
	case 'u':
	U=1;
	break;
	default:
	break;}
	}
	std::cout<<((A&E&I&O&U)?"YES":"NO");
	return 0;
}
8).
#include<iostream>
using namespace std;
int main()
{
    char arr[100000];
    char crr[] = {'a','e','i','o','u'};
    int n;
    cin >> n;
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i< 5; i++)
    {
        for(int j = 0; j <n; j++)
        {
            if(arr[j] == crr[i])    crr[i] = '1';
        }
    }
    for(int i = 0; i< 5; i++)
    {
        if(crr[i] != '1')   {cout << "NO"<<endl;    return 0;}
    }
    cout << "YES";
    return 0;
}

9).
#include <iostream>
using namespace std;
 
int main()
{
	int n;
    cin>>n;
    char*s=new char[n];
    bool vowel[5]={0};
    int count=0;
    cin>>s;
    for(int i=0;i<n;i++)
    {
    	if (count>=5) break;
    switch(s[i])
    {
    	case 'a':if(vowel[0]!=1){vowel[0]=1;count++;}break;
    	case 'e':if(vowel[1]!=1){vowel[1]=1;count++;}break;
    	case 'i':if(vowel[2]!=1){vowel[2]=1;count++;}break;
    	case 'o':if(vowel[3]!=1){vowel[3]=1;count++;}break;
    	case 'u':if(vowel[4]!=1){vowel[4]=1;count++;}break;
    			
    }
    }
    if(count>=5) cout<<"YES";
    else cout<<"NO";
    return 0;
}

C++14:
1).
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 10001
 
int main() {
    int size;
    scanf("%d", &size);
    
    char letters[MAX];
    scanf("%s", letters);
    
    bool vowels[5];
    for (int i = 0; i < 5; i++)
        vowels[i] = false;
    
    for (int i = 0; i < size; i++) {
        if (letters[i] == 'a')
            vowels[0] = true;
        else if (letters[i] == 'e')
            vowels[1] = true;
        else if (letters[i] == 'i')
            vowels[2] = true;
        else if (letters[i] == 'o')
            vowels[3] = true;
        else if (letters[i] == 'u')
            vowels[4] = true;
    }
    
    bool all_vowels = true;
    for (int i = 0; i < 5; i++)
        all_vowels &= vowels[i];
        
    if (all_vowels) printf("YES\n");
    else printf("NO\n");
}
2).
#include <stdio.h>
 
 
const char vowel[]="aeiou";
 
bool ok[26];
 
char s[1000005];
 
int n;
 
int main(){
	bool yes=true;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;s[i];i++)
	    ok[s[i]-'a']=true;
	for(int i=0;i<5;i++)
	    if (!ok[vowel[i]-'a'])
	        yes=false;
	if (yes)
	    printf("YES");
	else
	    printf("NO");
}
3).
#include<iostream>
using namespace std;
int main()
{
  int n,a=0,e=0,i=0,o=0,u=0;
  cin>>n;
  char ch,ch1[n+1];
  cin>>ch1;
  for(int j=0;j<n;j++)
  {
    ch=ch1[j];
    if(ch=='a')
     a++;
    else if(ch=='e')
     e++;
    else if(ch=='i')
     i++;
    else if(ch=='o')
     o++;
    else if(ch=='u')
    u++;
  }
  if((a>0)&&(e>0)&&(i>0)&&(o>0)&&(u>0))
    cout<<"YES";
  else
    cout<<"NO";
  return 0;
}



C#:
1).using System;
class MyHackerEarth 
{
    static void Main(string[] args) 
    {
        
        // Read input from stdin and provide input before running
        var line1 = System.Console.ReadLine().Trim();
        var n = Int32.Parse(line1);
        line1= System.Console.ReadLine().Trim();
        if (TestString(line1))
            Console.WriteLine("YES");
        else
            Console.WriteLine("NO");
    }
    static bool TestString(string str)
    {
        var vowels="aeiou";
        foreach(char c in vowels)
        {
            if (str.IndexOf(c)==-1)
                return false;
        }
        return true;
    }
}
2).
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
 
namespace ConsoleApplication68
{
    class Program
    {
        static void Main(string[] args)
        {
            long t = Convert.ToInt64(Console.ReadLine());
            string s=Console.ReadLine();
            char[]c=s.ToCharArray();
            long a=0,e=0,j=0,o=0,u=0;
            foreach (char i in c)
            {
                if (i == 'a')
                a++;
                if (i == 'e')
                e++;
                if (i == 'i')
                j++;
                if (i == 'o')
                o++;
                if (i == 'u')
                u++;
                
            }
            if (a >0 && e>0 && j>0 && o>0&&u>0)
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");
            Console.ReadLine();
        }
    }
}


Java:
0.75227 1
0.71273 3
0.70424 8
0.70423 14


Java 8:
1).
import java.util.Scanner;
public class AllVowels {
 
    public static boolean check(int p,int q,int r,int s,int t){
        if(p>0 && q>0 && r>0 && s>0 && t>0)
            return true;
        else
            return false;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int l=sc.nextInt();
        boolean f=false;
        String s=sc.next();
        char ch;
        int a=0,e=0,i=0,o=0,u=0;
        for(int x=0;x<l;x++){
            ch=s.charAt(x);
            if(ch=='a')
                a++;
            else if(ch=='e' )
                e++;
            else if(ch=='i')
                i++;
            else if(ch=='o')
                o++;
            else if (ch=='u'){
                u++;
            }
            f=check(a,e,i,o,u);
            if(f==true){
                break;
            }
        }
        if(f==true)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
    
}
2).
import java.util.*;
 
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        //
        // Read input from stdin and provide input before running
        // Use either of these methods for input
 
        //BufferedReader
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //String line = br.readLine();
        //int N = Integer.parseInt(line);

        //Scanner
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
        String input = s.next();
        if(input.contains("a") && input.contains("e") && input.contains("i")
        && input.contains("o") && input.contains("u"))
        {
            System.out.println("YES");
        }
        else
        {
            System.out.println("NO");
        }
    }
}

3).
import java.io.*;
import java.util.*;
 
 
class TestClass {
    public static void main(String args[] ) throws Exception {
       BufferedReader s = new BufferedReader(new InputStreamReader(System.in));
       int n = Integer.parseInt(s.readLine());
           String q = s.readLine();
           Map<Character,Integer> d = new HashMap<>();
           int e = n;
           for(int i=0;i<e;i++){
               char v = q.charAt(i);
                if(!d.containsKey(v)){
                    d.put(v,1);
                }
                else{
                    d.put(v,d.get(v)+1);
                }
           }
           int y = 0;
           for(Character key : d.keySet()){
               if(key=='a' || key=='u' || key=='e' || key=='i' || key=='o'){
               y++;
              
               }
               else continue;
           }
           
           if(y<5)  System.out.println("NO");
           else     System.out.println("YES");
       }
    }

4).
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
 
import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        String st=br.readLine();
        
        if(st.contains("a")&&st.contains("e")&&st.contains("i")&&st.contains("o")&&
        st.contains("u")){
            System.out.println("YES");
        }
        
        else
        System.out.println("NO");
 
 
    }
}
5).
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String z = br.readLine();
        String name = br.readLine();  
        char arr[] ;
        int val[] = new int[26];
        arr = name.toCharArray();
        int x ; 
        for(int i = 0; i< arr.length; i++)
        {
            x = find_index(arr[i]);
            val[x]++;
            
        }
        
        if((val[0]!= 0)&&(val[4]!= 0)&&(val[8]!= 0)&&(val[14]!= 0)&&(val[20]!= 0))
        {
            System.out.println("YES");
        }
        else
        {
            System.out.println("NO");
        }
        
       
    }
    
    public static int find_index(char a)
    {
        return a - 'a';
    }
}

Python:
1).
n=input()
y=raw_input()
v=set(['a','e','i','o','u'])
if v.issubset(set(y.lower())):
    print "YES"
else:
    print "NO"
2).
a = input();
b = raw_input();
vowelArr = [0,4,8,14,20];
 
c = [0 for i in xrange(26)];
 
for i in xrange(a) :
	d = ord(b[i]) - 97;
	c[d] = c[d] + 1; 
 
doesAllExist = 0;
for i in vowelArr :
	if(c[i] == 0) :
		break;
	else :
		doesAllExist = doesAllExist + 1;
	
if(doesAllExist == 5): 
	print "YES"
else :
	print "NO"
3).
a = "a"
e = "e"
i = "i"
o = "o"
u = "u"
 
 
num_of_test_cases = raw_input()
num_of_test_cases = int(num_of_test_cases)
 
input_str = raw_input()
 
if a in input_str and e in input_str and i in input_str and o in input_str and u in input_str:
    print "YES"
else: print "NO"
4).
def main() :
	n = input()
	s = raw_input()
	ans = "NO"
 
	if s.find('a') == -1 :
		print ans
		return
	if s.find('e') == -1 :
		print ans
		return
	if s.find('i') == -1 :
		print ans
		return
	if s.find('o') == -1 :
		print ans
		return
	if s.find('u') == -1 :
		print ans
		return
 
	ans = "YES"
	print ans
 
if __name__ == '__main__':
	main()
5).
n=int(raw_input())
lis=['a','e','i','o','u']
flag=0
st=list(raw_input())
# print st
for j in lis:
  if j in st:
    flag=1
  else:
    flag=0
    print "NO"
    break
    break
if flag==1:
  print "YES"
6).
n=int(input())
n1=raw_input()
if('a' in n1 and 'e' in n1 and 'i' in n1 and 'o' in n1 and 'u' in n1):
    print 'YES'
else:
    print 'NO'

Python 3:
1).
input()
lkp = {'a':1,'e':1,'i':1,'o':1,'u':1}
c = 0
for i in input():
    if i in lkp:
        c += 1
        del lkp[i]
    if c == 5:
        break
if c == 5:
    print("YES")
else:
    print("NO")
2).
T = int(input())
str1 = input()
 
count = 0
lst2 =[]
lst = ['a','e','i','o','u']
if len(str1) > 5:
    for i in range(len(lst)):
        if lst[i] in str1:
            if lst[i] not in lst2:
                lst2.append(lst[i])
                count += 1
                if count > 5:
                    break
    
    if count == 5:
        print("YES")
    else:
        print("NO")
        
else:
    print("NO")

3).
vowels = set(['a','e','i','o','u'])
 
def main():
    n = int(input())
    s = input()
    print('YES' if vowels.issubset(set(s)) else 'NO')
 
main()

4).
n = input()
s = input()
s1 = 'aeiou'
d = {}
for i in s:
    if i in d:
        d[i] +=1
    else:
        d[i] = 1
c = 0
for i in s1:
    if i in d:
        if d[i] >=1:
            c +=1
print("YES" if c == 5 else "NO")


Pascal:
Program HiHere;
VAR a,e,i,o,u,i2,n:int64; c:char;
Begin
Readln(n);
for i:=1 to n do
Begin
Read(c);
if (c = 'a') then a:=1;
if (c = 'e') then e:=1;
if (c = 'i') then i2:=1;
if (c = 'o') then o:=1;
if (c = 'u') then u:=1;
end;
if (a + e + i2 + o + u = 5) then Writeln('YES') else Writeln('NO');
Readln;
END.

Scala:
object HelloWorld {
  def main(args: Array[String]) {
 
    val ip= io.Source.stdin.getLines().take(2).toList
  
  val s = ip(1);
    if (s.contains('a') && s.contains('e') && s.contains('i') && s.contains('o') && s.contains('u'))
      println("YES")
    else
      println("NO")
 
 
  }
}

Ruby:
1).
s=gets.chomp.to_i
arr=Hash.new(0)
str=gets.chomp.split("")
str.each do |x|
	arr[x]+=1
end
if arr["a"]>0&&arr["e"]>0&&arr["i"]>0&&arr["o"]>0&&arr["u"]>0
	puts "YES"
else
	puts "NO"
end

2).
=begin
# Sample code to perform I/O:
 
name = gets.chomp                # Reading input from STDIN
print "Hi, #{name}.\n"           # Writing output to STDOUT
 
# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
=end
 
# Write your code here
n = gets.chomp.to_i
str = gets.chomp
flag = true
['a','e','i','o','u'].each do |x|
  unless str.include? x
    flag = false
    break
  end
end
if flag
  puts "YES"
else
  puts "NO"
end

3).
vowels = ["a","e","i","o","u"]
n = gets.to_i
s = gets.strip
flag = 0
vowels.each do |vowel|
	if s.include? vowel
		next
	else
		flag = 1
		break
	end		
end
puts flag == 0 ? "YES" : "NO"

4).
num = gets.chomp
str = gets.chomp
print str.index("a") && str.index("e") && str.index("i") && str.index("o") && str.index("u") ? "YES" : "NO" 


Perl:
1).
use strict;
use warnings;
my $n = <STDIN>;
#if(looks_like_number($n)){
if($n>=1 && $n<=10000){
	my $str = <STDIN>;
	if(length($str) == $n){
		if($n<5){
			print "NO";
		}
		else{
			if(index($str,'a')!=-1 && index($str,'e')!=-1 && index($str,'i')!=-1
				&& index($str,'o')!=-1 && index($str,'u')!=-1){
					print "YES";
			}
			else{
				print "NO";
			}
		}
	}
}
#}

2).
use strict;
 
=comment
# Read input from stdin and provide input before running code
 
# Echo input to output.
while(my $fred = <STDIN>) {
    print $fred;
}
=cut
my $var=<STDIN>;
my $str=<STDIN>;
if($str=~/a/ && $str=~/u/&& $str=~/i/ && $str=~/b/ && $str=~/o/){
	print "YES";	
}
else{
	print "NO";	
}
##print 'Hello World!'

3).
use strict;
use warnings;
my $n = <STDIN>;
my $s = <STDIN>;
if(index($s,'a') != -1 && index($s,'e') != -1 && index($s,'i') != -1 && index($s,'o') != -1 && index($s,'u') != -1 ){
	print "YES";
}
else {
	print "NO";
}


JavaScript(Node.js):
1).
function main(input) {
   input = input.split("\n");
   var   str = input[1],
      count = 0,
      vowels = "aeiou";
      
  for(var i=0;i<vowels.length;i++){
  	if(str.indexOf(vowels[i]) > -1){
  		count++;
  	}
  }
  console.log(count == 5 ? "YES" : "NO");
      
}
 
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;
});
 
process.stdin.on("end", function () {
   main(stdin_input);
});

2).
function main(input) {
    if(input.includes("a") && input.includes("e") && input.includes("i") && input.includes("o") && input.includes("u"))
    console.log("YES")
    else
    console.log("NO")
    
}
 
process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";
 
process.stdin.on("data", function (input) {
    stdin_input += input;
});
 
process.stdin.on("end", function () {
   main(stdin_input);
});
 

*/