  #include<iostream>
#include<string>
#include<thread>
#include<chrono>
#include<cctype>
#include<fstream>
#include<vector>
#define ANSI_COLOUR_RED "\x1b[31m"
#define ANSI_COLOUR_RESET "\x1b[0m"
using namespace std;
//please keep in mind that this program is a single user program.
//setup a friend function for this class for the user to create a strong password
//The comments below in the file handling part are extremely important to know what is happening
class customerinfo
{
private:
 string username;
 string password;
 string DOB;
 int mobnumber;
public:
 customerinfo(string name = "none", string pass = "no", string date = "0/0/0", int mob = 0)
 {
  username = name;
  password = pass;
  DOB = date;
  mobnumber = mob;
 }
 void set_name(const string& str)
 {
  username = str;
 }
 void set_dob(const string& ddr)
 {
  DOB = ddr;
 }
 void set_pass(const string& ppr)
 {
  password = ppr;
 }
 void set_mob(int k)
 {
  mobnumber = k;
 }
 string get_name()
 {
  return username;
 }
 string get_pass()
 {
  return password;
 }
 string get_DOB()
 {
  return DOB;
 }
 int get_mob()
 {
  return mobnumber;
 }
 void display_info()
 {
  cout << "\nThe information that you have entered is as follows:-";
  cout << "\nNAME: " << username;
  cout << "\npassword: " << password;
  cout << "\nDOB: " << DOB;
  cout << "\nMobile number: " << mobnumber;
 }
 friend int password_strength_evaluator(const string &pass);
};
class shoppingcart
{
public:
 vector<int> nums = {0};   //the shortisted array object has to be put in this vector object called nums and then calculate the total price.
/*public:
 void set_vector(int arr[])
 {
  for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
  {
   nums[i] = arr[i];
  }
 }*/



 friend int bill_calculator(vector<int> tr);
};

int bill_calculator(vector<int> tr)
{
 int sum = 0;
 for (int i = 0; i < tr.size(); i++)
 {
  sum = sum + tr[i];
 }
 return sum;
}


//creating supporting functions for the help of the password strength evaluation's main function

int has_upper(const string& trass)
{
 int count = 0;
 for(int i = 0; i < trass.length(); i++)
 {
  if (trass[i] >= 65 && trass[i] <= 90)
  {
   count++;
  }
 }
 if (count == 0)
  return 0;
 else
  return 1;
}
int has_lower(const string& grass)
{
 int count = 0;
 for (int i = 0; i < grass.length(); i++)
 {
  if (grass[i] >= 97 && grass[i] <= 122)
  {
   count++;
  }
 }
 if (count == 0)
  return 0;
 else
  return 1;
}
int has_specialcharacters(const string& lass)
{
 int count = 0;
 for (int i = 0; i < lass.length(); i++)
 {
  if (!(isalnum(lass[i])))
  {
   count++;   //if the character is NOT alphanumeric then +1
  }
 }
 if (count == 0)
  return 0;
 else
  return 1;
}
//the function of the password generator that will be called in the main function
int password_strength_evaluator(const string& pass)  //if this function upon evaluation return 0 the user will be asked to set the password again.
{                                                    //this function is set to return 0 if pass is not strong and 1 if the pass is strong.
 cout << "\nSending the password to the other helper functions for evaluation";
 if ((has_upper(pass) == 1) && (has_lower(pass) == 1) && (has_specialcharacters(pass) == 1))
 {
  return 1;
 }
 else
 {
  return 0;
 }
}


int main()
{
 customerinfo c1;  //only one object of the class is required as the programme is limited to one user only
 while (true)  //this is an infinite loop which will keep on executing until a break statement is encountered because the statement true will always remain true.
 {

    cout << "88888888888 ,ad8888ba,     ,ad8888ba,   88888888ba,               88888888888 88888888ba  88888888888 888b      88 888888888888 8b        d8  \n";
    cout << "88         d8\"'    `\"8b   d8\"'    `\"8b  88      `\"8b              88          88      \"8b 88          8888b     88          ,88  Y8,    ,8P   \n";
    cout << "88        d8'        `8b d8'        `8b 88        `8b             88          88      ,8P 88          88 `8b    88        ,88\"    Y8,  ,8P    \n";
    cout << "88aaaaa   88          88 88          88 88         88             88aaaaa     88aaaaaa8P' 88aaaaa     88  `8b   88      ,88\"       \"8aa8\"     \n";
    cout << "88\"\"\"\"\"   88          88 88          88 88         88             88\"\"\"\"\"     88\"\"\"88'   88\"\"\"\"\"     88   `8b  88    ,88\"          `88'      \n";
    cout << "88        Y8,        ,8P Y8,        ,8P 88         8P             88          88    `8b   88          88    `8b 88  ,88\"             88       \n";
    cout << "88         Y8a.    .a8P   Y8a.    .a8P  88      .a8P              88          88     `8b  88          88     `8888 88\"               88       \n";
    cout << "88          `\"Y8888Y\"'     `\"Y8888Y\"'   88888888Y\"'               88          88      `8b 88888888888 88      `888 888888888888      88       \n";
    cout << "                                                                                                                                               \n";

  cout << "\n\n\n->Please press 1 to SIGN UP";
  cout << "\n->Please press 2 to LOG IN";
  cout << "\n->Please press 3 to LOG OUT/EXIT";
  int choice;
  cin >> choice;
  cin.ignore();
  if (choice == 1)   //the user has chosen to sign up
  {
   system("cls");
   cout << "\nYou have chosen to create a new account\nPlease enter the following details:-\n";


cout << "USERNAME: ";
   string n;
   getline(cin, n);
   c1.set_name(n);
   cout << "\nDate of birth: ";
   string d;
   getline(cin, d);
   c1.set_dob(d);
   string pass;
   int strength;
   do
   {
    cout << "\nPassword to be set: ";
    getline(cin, pass);
    strength = password_strength_evaluator(pass);
    if (strength == 0)
    {
     cout << "\nThe password that you have entered is not strong. Please reenter the password.";
     cout << "\nIt should contain at least one uppercase , one lowercase and one special character!!";
    }
   } while (strength == 0);

   cout << "\nThe password is strong, so the new password is set";
   c1.set_pass(pass);
   cout << "\nMobile number: ";
   int k;
   cin >> k;
   cin.ignore();
   c1.set_mob(k);
   cout << "\nThe information that you have entered is: ";
   c1.display_info();
   //NOW A FILE HAS TO BE CREATED VIA FILE HANDLING TO CREATE A SEPARATE FILE FOR THE USER
   ofstream objfile("Customerinfo_from_project.txt");  //this will open a text file named customerinfo_from_project.
   objfile << c1.get_name() << endl;    //these statements are there to insert all the content into the file to create the file
   objfile << c1.get_DOB() << endl;     //this order in which the information if fed inside the file is paramount to t=retrieve it back also
   objfile << c1.get_pass() << endl;
   objfile << c1.get_mob() << endl;
   objfile.close();
   break;
  }
  else if (choice == 2)   //the user has chosen to log in
  {
   system("cls");
   bool check = false;
   do
   {
    string* conpass = new string;
    cout << "\nPlease enter the password to login to your account, retrieve your information and see your previous orders: ";
    getline(cin, *conpass);
    ifstream infile;   //file object and ifstream is written for reading the contents from the file.
    infile.open("Customerinfo_from_project.txt");  //this will open the file which is ALREADY/MUST BE existing.
    if (!infile)
    {
     cout << "\nThe file can't be opened";
     return 0;
    }
    //NOW CHECK FOR THE PASS SAME AS THE CONPASS INSIDE THE FILE!!
    //the order is name dob password and then mobile number for each user so we will use a while loop to read all of these things in order and then check the conpass with the password until true
    string username, dob, password;
    int mobile;

    while (infile >> username >> dob >> password >> mobile)  //read everything in order from the existing file into thhe infile ifstream(reading) object
    {                                    //In summary, the loop will read as many sets of values from the file as there are, and it will stop when it encounters the end of the file or when it fails to read values into any of the variables. Any remaining values in the file after reading all the variables will be left untouched.
     if (password == *conpass)
     {
      cout << "\nThe login was successful! your information is as follows:-";
      //cannot use the display function as we have to read from the file only WHICH IS ARRANGED IN A SPECIFIC ORDER for EACH USER
      cout << "\nWELCOME BACK " << username << "!!";
      cout << "\npassword: " << password;
      cout << "\nDOB: " << dob;
      cout << "\nMobile number: " << mobile;
      check = true;
      break;    //since EOF has been achieved the break statement may or may not be necessary. this can be verified by running the program even after this break is removed
     }
    }
    if (!check)
    {
     cout << "\nLOGIN UNSUCESSFULL";
     cout << "\nThe password that you have entered is incorrect";
     cout << "\nPlease reenter the correct password.";
     //After reading in the values from the file below...I will have to set the file pointer again back to the beggining for reexecution!!
    }
    delete conpass;
    infile.close();
   } while (!check);   //this means do the abve tasks while the check2 boolean is not true


   break;
  }
  else if (choice == 3)
  {
   for (int i = 0; i <= 5; i++)
   {
    cout << "\nThe programme has ended !!" << flush;


this_thread::sleep_for(chrono::seconds(1));  //pauses the execution of the program for 1 seconds.
    cout << "\r                        " << flush;    //clears the previous message
    this_thread::sleep_for(chrono::seconds(1));   //pauses the programme for 1 second until the executions of the code is not completed for 5 times
   }
   return 0;
  }
  else
  {
   cout << "\nPlease enter a valid choice";    //upon the user entering any other invalid choice the user will be prompted to enter the choices again.
  }
 }
 system("cls");
this_thread::sleep_for(chrono::seconds(1));
 shoppingcart s1;   //this has to be declared outside because if the user decides to order more dishes again from a different cuisines I will have to add th price total
 int ultimate = 0;
 while (ultimate == 0)
 {
  cout << "\nPlease enter index of one of the following choices as per your requirement";
  int tr = 0;
  while (tr == 0)
  {
   cout << "\n 1.AVAILABLE CUISINES\n 2.MOST ORDERED DISHES\n 3.BEST RESTAURANTS \n index: ";
   int choice;
   cin >> choice;
   if (choice == 1)
   {
    tr = 1;
    cout << "\nThe available cuisines are as follows: ";
    cout << "\n1.Chinese\n2.Continental\n3.Italian\n4.Mughlai\n5.South Indian\n6.Mexican";
    cout << "\nPlease enter the index of the cuisine that you want to order: ";
    int choicecuisine;
    bool isvalid = true;
    do
    {
     cin >> choicecuisine;
     switch (choicecuisine)
     {

     case 1:
     {
         system("cls");
    std::cout << "                     __" << std::endl;
    std::cout << "             <<<|>> |PARADISE|" << std::endl;
    std::cout << "               |__|[] [] []|" << std::endl;
    std::cout << "              |[] []|        |" << std::endl;
    std::cout << "   _||[][][]|" << std::endl;
    std::cout << "  |                            |" << std::endl;
    std::cout << "  |   <>   CHINA TOWN   <>   |" <<std::endl;
    std::cout << "  |____|" << std::endl;
    std::cout << " /::::::::::::::::::::::::::::::\\" << std::endl;
    std::cout << "/::::::::::::::::::::::::::::::::\\" << std::endl;
    std::cout << "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU" << std::endl;
    std::cout << " |  __   __ |\\.--------." << std::endl;
    std::cout << " | |vvv|vvv|vvv|vvv|  || _ _ || | | Hotel  |" << std::endl;
    std::cout << " | |   |   |   |   |  ||||||| | |Entrance|__" << std::endl;
    std::cout << " | |%%%+%%%+%%%+%%%|  ||||||| |/'--------'" << std::endl;
    std::cout << " | |%%%|%%%|%%%|%%%|  ||     || |" << std::endl;
    std::cout << " | |%%%|%%%|%%%|%%%|  ||o    || |()         ()" << std::endl;
    std::cout << " |  \"\"\"\"\"\"\"\"\"\"\"\"\"\"   ||     || ||| /     \\ ||" << std::endl;
    std::cout << " |                    ||_|| |||/       \\||lc" << std::endl;
    std::cout << "  ~~/_\\~ /         \\" << std::endl;
    std::cout << ".:..:..:..:..:..:..:..:..:..:..:.<>.:..:..:..:..:..:..:..:..:..:..:." << std::endl;
      cout << "\nThe Chinese dishes are as follows :-";
      cout << "\n1.}Honey chilli potato => 200/-";
      cout << "\n2.}Dumplings => 50/-";
      cout << "\n3.}Chowmein => 300/-";
       cout << "\n4.}Peking Duck => 400/-";
       cout << "\n5.}Kung Pao Chicken  => 300/-";
       cout << "\n6.}Hot Pot => 300/-";
        cout << "\n7.}Spring Rolls => 200/-";
        cout << "\n8.}Mapo Tofu => 250/-";
        cout << "\n9.}Szechuan Beef  => 200/-";
        cout << "\n10.}Shrimp Fried Rice => 400/-";
        cout << "\n11.}Sweet and Sour Pork  => 500/-";
        cout << "\n12.}Egg Rolls  => 300/-";
        cout << "\n13.}Ma Po Dou Fu=> 300/-";
        cout << "\n14.}Char Siu => 100/-";
        cout << "\n15.}Dim Sum=> 150/-";
        cout << "\n16.}Yangzhou Fried Rice => 300/-";
        cout << "\n17.}Sesame Chicken => 300/-";
        cout << "\n18.}Scallion Pancakes  => 300/-";
        cout << "\n19.}Wonton Soup  => 250/-";
        cout << "\n20.}Beef Noodle Soup => 200/-";
        cout << "\n21.}Xiao Long Bao=> 300/-";
        cout << "\n22.}General Tso's Chicken  => 300/-";
        cout << "\n23.}Salt and Pepper Squid  => 400/-";
        cout << "\n24.}Baozi  => 400/-";
        cout << "\n25.}Sichuan Hot Pot  => 500/-";
        cout << "\n26.}Fried Wontons   => 200/-";
        cout << "\n27.}Buddha's Delight  => 300/-";
        cout << "\n28.}Pineapple Chicken => 500/-";
        cout << "\n29.}Steamed Fish  => 500/-";
        cout << "\n30.}Dan Dan Noodles  => 300/-";
        cout << "\n31.}Jianbing  => 300/-";
      int counttillnumofdishes;
      do
      {
       cout << "\nPlease enter the index of the dish that you desire: ";
       int* choiceofdish = new int;
       int* qty = new int;
       bool validity = true;
       int arr[3] = { 200 , 50 , 300 };             //size of the array has to be altered in order to add more dishes
       do
       {
        cin >> *choiceofdish;
        if (*choiceofdish == 1)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;   //handle the error for the incorrect quantity entered.
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[0]);
         }
        }
        else if (*choiceofdish == 2)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[1]);
         }
        }
        else if (*choiceofdish == 3)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[2]);
         }
        }
        else
        {
         validity = false;
         cout << "\nPlease enter the correct choice: ";
        }
        delete qty;
        delete choiceofdish;
       } while (validity == false);
       cout << "\nPlease enter 1 for ordering another dish from the same cuisine OR 2 for finishing up the order: ";
       int tried;
       cin >> tried;
       if (tried == 1)
       {
        counttillnumofdishes = 0;
       }
       else if (tried == 2)
       {
        counttillnumofdishes = 1;
       }
      } while (counttillnumofdishes == 0);

      isvalid = true;

      break;
     }
     case 2:
     {
         system("cls");
         std::cout << "                               @[=]@\n";
    std::cout << "                            @@@@|@@@@\n";
    std::cout << "                                ,,|,,\n";
    std::cout << "    ,                          ;IIIII;                          ,\n";
    std::cout << "  , I ,                         ;UUU;                         , I ,\n";
    std::cout << "  I~@I                          `!'                          I@~I\n";
    std::cout << "  =;V;=                 ,,                                    =;V;=\n";
    std::cout << "                       ,II,                            \n";
    std::cout << "                      ,I;;I,                                           ,\n";
    std::cout << "          ,           I~@@~I           ,                             , I ,\n";
    std::cout << "        , I ,         ;\\;;/;         , I ,           _           I~@~I\n";
    std::cout << "      I~@~I       ;;;;       I~@~I        |\\ Y Y\\_;/\\/;\n";
    std::cout << "!/  ;\\/;  \\!)(!/  ;\\/;  \\!| \\__\\\n";
    std::cout << "|_ /_\\ |  ()  |_ /__\\ _|  | |                    |\n";
    std::cout << "[]     | |     []        []     | |     []  | |@ Continental Hub @|\n";
    std::cout << " )(     ) (     )(          )(     ) (     )(   | |             |\n";
    std::cout << "                                                     \\|____|lc\n\n";
      cout << "\nThe Continental dishes are as follows :-";
      cout << "\n1.}Coq Au Vin => 500/-";
      cout << "\n2.}Ratatouille => 850/-";
      cout << "\n3.}Spaghetti Carbonara => 990/-";
      cout << "\n4.}Beef Bourguignon => 990/-";
      cout << "\n5.}Paella => 990/-";
      cout << "\n6.}Beef Wellington => 990/-";
      cout << "\n7.}Chicken Cordon Bleu=> 990/-";
      cout << "\n8.}Quiche Lorraine => 990/-";
      cout << "\n9.}Beef Stroganoff => 990/-";
      cout << "\n10.}Fish and Chips=> 990/-";
      cout << "\n11.}Chicken Parmesan => 990/-";
      cout << "\n12.}Caesar Salad => 990/-";
      cout << "\n13.}Shepherd's Pie => 990/-";
      cout << "\n14.}Tiramisu => 990/-";
      cout << "\n15.}Risotto=> 990/-";
      cout << "\n16.}Chicken Alfredo => 990/-";
      cout << "\n17.}Bouillabaisse=> 990/-";
      cout << "\n18.}Croque Monsieur=> 990/-";
      cout << "\n19.}Beef Carpaccio => 990/-";
      cout << "\n20.}Goulash=> 990/-";
      cout << "\n21.}Potato Gratin=> 990/-";
      cout << "\n22.}Eggs Benedict=> 990/-";
      cout << "\n23.}Beef Tacos=> 990/-";
      cout << "\n24.}French Onion Soup=> 990/-";
      cout << "\n25.}Beef Lasagna=> 990/-";
      cout << "\n26.}Duck à l'Orange=> 990/-";
      cout << "\n27.}Shrimp Scampi=> 990/-";
      cout << "\n28.}Beef Ragù=> 990/-";
      cout << "\n29.}Chicken Fricassee=> 990/-";


      int counttillnumofdishes;
      do
      {
       cout << "\nPlease enter the index of the dish that you desire: ";
       int* choiceofdish = new int;
       int* qty = new int;
       bool validity = true;
       int arr[3] = { 500 , 850 , 990 };           //size of the array has to be altered in order to add more dishes

do
       {
        cin >> *choiceofdish;
        if (*choiceofdish == 1)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;   //handle the error for the incorrect quantity entered.
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[0]);
         }
        }
        else if (*choiceofdish == 2)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[1]);
         }
        }
        else if (*choiceofdish == 3)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[2]);
         }
        }
        else
        {
         validity = false;
         cout << "\nPlease enter the correct choice: ";
        }
        delete qty;
        delete choiceofdish;
       } while (validity == false);
       cout << "\nPlease enter 1 for ordering another dish from the same quisine OR 2 for finishing up the order: ";
       int tried;
       cin >> tried;
       if (tried == 1)
       {
        counttillnumofdishes = 0;
       }
       else if (tried == 2)
       {
        counttillnumofdishes = 1;
       }
      } while (counttillnumofdishes == 0);

      isvalid = true;
      break;
     }

     case 3:
     {
         system("cls");
         std::cout << " ______\n";
    std::cout << "/      _ _ - -                         __--    \\\n";
    std::cout << "/  _-               _ -  _ -    _-               \\\n";
    std::cout << "/______\\\n";
    std::cout << " |       ____       |\n";
    std::cout << " |      /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\      |\n";
    std::cout << " |     /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\     |\n";
    std::cout << " |  _ UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU _  |\n";
    std::cout << " | |%%| |  ___   _ | |%%| |\n";
    std::cout << " | |%%| | | P | I | Z | Z | A |  || _ _ || | |%%| |\n";
    std::cout << " | |%%| | |   |   |   |   |   |  ||||||| | |%%| |\n";
    std::cout << " | |%%| | |||||_|  ||||||| | |%%| |\n";
    std::cout << " | ==== | |%%%|%%%|%%%|%%%|%%%|  ||     || | ==== |\n";
    std::cout << " |      | |%%%|%%%|%%%|%%%|%%%|  ||o    || |      |\n";
    std::cout << " |_| =====================  ||     || |_|\n";
    std::cout << " _|___|||||__\n";
    std::cout << " ____/\\_\n";
      cout << "\nThe Italian dishes are as follows :-";
      cout << "\n1.}Pizza => 300";
      cout << "\n2.}Pasta => 150";
      cout << "\n3.}Spaghetti and meatballs => 490";
      cout << "\n4.}Pizza Margherita => 300";
      cout << "\n5.}Spaghetti Bolognese=> 300";
      cout << "\n6.}Lasagna => 300";
      cout << "\n7.}Risotto alla Milanese=> 300";
      cout << "\n8.}Fettuccine Alfredo=> 300";
      cout << "\n9.}Ravioli => 300";
      cout << "\n10.}Osso Buco => 300";
      cout << "\n11.}Caprese Salad=> 300";
      cout << "\n12.}Tiramisu => 300";
      cout << "\n13.}Bruschetta => 300";
      cout << "\n14.}Cannelloni => 300";
      cout << "\n15.}Carbonara => 300";
      cout << "\n16.}Panzanella => 300";
      cout << "\n17.}Gnocchi => 300";
      cout << "\n18.}Minestrone Soup => 300";
      cout << "\n19.}Prosciutto e Melone  => 300";
      cout << "\n20.}Arancini => 300";
       cout << "\n21.}Focaccia => 300";
      cout << "\n22.}Pasta Primavera => 300";
      cout << "\n23.}Insalata Caprese => 300";
       cout << "\n24.}Calzone => 300";
       cout << "\n25.}Polenta => 300";
        cout << "\n26.}Orecchiette => 300";
       cout << "\n27.}Vitello Tonnato => 300";
        cout << "\n28.}Panna Cotta => 300";
        cout << "\n29.}Cioppino => 300";
        cout << "\n30.}Zuppa Toscana=> 300";
        cout << "\n31.}Amatriciana=> 300";
        cout << "\n32.}Saltimbocca=> 300";
        cout << "\n33.}Cacio e Pepe=> 300";
        cout << "\n34.}Cannoli=> 300";
        cout << "\n35.}Cannoli=> 300";
        cout << "\n36.}Pesto Genovese=> 300";
      int counttillnumofdishes;
      do
      {
       cout << "\nPlease enter the index of the dish that you desire: ";
       int* choiceofdish = new int;
       int* qty = new int;
       bool validity = true;  //for the correct choice of the dishes.
       //see that the price of the each of the dishes is being stored according to the index in an array.
       int arr[3] = { 300 , 150 , 490 };  //the size of this array needs to be changed as per the number of teh dishes.
       //even the price of the dish has to be stored in the array beforehand
       do
       {
        cin >> *choiceofdish;
        if (*choiceofdish == 1)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;   //handle the error for the incorrect quantity entered.
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[0]);
         }
        }
        else if (*choiceofdish == 2)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[1]);
         }
        }
        else if (*choiceofdish == 3)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[2]);
         }
        }
        else
        {
         validity = false;
         cout << "\nPlease enter the correct choice: ";
        }
        delete qty;
        delete choiceofdish;
       } while (validity == false);
       cout << "\nPlease enter 1 for ordering another dish from the same quisine OR 2 for finishing up the order: ";
       int tried;
       cin >> tried;
       if (tried == 1)
       {
        counttillnumofdishes = 0;
       }
       else if (tried == 2)
       {
        counttillnumofdishes = 1;
       }
      } while (counttillnumofdishes == 0);
      isvalid = true;
      break;
     }
     case 4:
     {
         system("cls");
           std::cout << "88b           d88                         88          88            88                88888888888 88                                           " << std::endl;
    std::cout << "888b         d888                         88          88            \"\"                88          \"\"                        ,d                " << std::endl;
    std::cout << "88`8b       d8'88                         88          88                              88                                    88                " << std::endl;
    std::cout << "88 `8b     d8' 88 88       88  ,adPPYb,d8 88,dPPYba,  88 ,adPPYYba, 88                88aaaaa     88  ,adPPYba, ,adPPYba, MM88MMM ,adPPYYba,  " << std::endl;
    std::cout << "88  `8b   d8'  88 88       88 a8\"    `Y88 88P'    \"8a 88 \"\"     `Y8 88                88\"\"\"\"\"     88 a8P___88 I8[    \"\"   88    \"\"     `Y8  " << std::endl;
    std::cout << "88   `8b d8'   88 88       88 8b       88 88       88 88 ,adPPPPP88 88                88          88 8PP\"\"\"\"\"\"\"  `\"Y8ba,    88    ,adPPPPP88  " << std::endl;
    std::cout << "88    `888'    88 \"8a,   ,a88 \"8a,   ,d88 88       88 88 88,    ,88 88                88          88 \"8b,   ,aa aa    ]8I   88,   88,    ,88  " << std::endl;
    std::cout << "88     `8'     88  `\"YbbdP'Y8  `\"YbbdP\"Y8 88       88 88 `\"8bbdP\"Y8 88                88          88  `\"Ybbd8\"' `\"YbbdP\"'   \"Y888 `\"8bbdP\"Y8  " << std::endl;
    std::cout << "                               aa,    ,88                                                                                                      " << std::endl;
    std::cout << "                                \"Y8bbdP\"                                                                                                   " << std::endl;

      cout << "\nThe Mughlai dishes are as follows :-";
      cout << "\n1. Biryani => Price: ₹120";
cout << "\n2. Butter Chicken (Murgh Makhani) => Price: ₹130";
cout << "\n3. Rogan Josh => Price: ₹110";
cout << "\n4. Chicken Tikka Masala => Price: ₹140";
cout << "\n5. Kebabs => Price: ₹100";
cout << "\n6. Shahi Paneer => Price: ₹110";
cout << "\n7. Chicken Korma => Price: ₹120";
cout << "\n8. Mutton Korma => Price: ₹130";
cout << "\n9. Dal Makhani => Price: ₹150";
cout << "\n10. Tandoori Chicken => Price: ₹140";
cout << "\n11. Seekh Kebab => Price: ₹130";
cout << "\n12. Palak Paneer => Price: ₹110";
cout << "\n13. Chicken Biryani => Price: ₹120";
cout << "\n14. Nihari => Price: ₹100";
cout << "\n15. Dum Pukht => Price: ₹140";
cout << "\n16. Malai Kofta => Price: ₹140";
cout << "\n17. Galouti Kebab => Price: ₹120";
cout << "\n18. Reshmi Kebab => Price: ₹130";
cout << "\n19. Paneer Tikka => Price: ₹120";
cout << "\n20. Korma => Price: ₹150";
cout << "\n21. Mughlai Paratha => Price: ₹120";
cout << "\n22. Mutton Biryani => Price: ₹130";
cout << "\n23. Chapli Kebab => Price: ₹110";
cout << "\n24. Murgh Malaiwala => Price: ₹130";
cout << "\n25. Sheermal => Price: ₹120";
cout << "\n26. Boti Kebab => Price: ₹130";
cout << "\n27. Murg Musallam => Price: ₹110";
cout << "\n28. Chicken Rezala => Price: ₹120";
cout << "\n29. Pasanda => Price: ₹130";
cout << "\n30. Shami Kebab => Price: ₹110";
cout << "\n31. Tandoori Fish => Price: ₹140";
cout << "\n32. Shahi Tukda => Price: ₹140";
cout << "\n33. Bhuna Gosht => Price: ₹120";
cout << "\n34. Zafrani Pulao => Price: ₹130";
cout << "\n35. Murgh Do Pyaza => Price: ₹120";


int counttillnumofdishes;
      do
      {
       cout << "\nPlease enter the index of the dish that you desire: ";
       int* choiceofdish = new int;
       int* qty = new int;
       bool validity = true;
       int arr[3] = { 300 , 350 , 550 };         //size of the array has to be altered in order to add more dishes
       do
       {
        cin >> *choiceofdish;
        if (*choiceofdish == 1)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;   //handle the error for the incorrect quantity entered.
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[0]);
         }
        }
        else if (*choiceofdish == 2)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[1]);
         }
        }
        else if (*choiceofdish == 3)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[2]);
         }
        }
        else
        {
         validity = false;
         cout << "\nPlease enter the correct choice: ";
        }
        delete qty;
        delete choiceofdish;
       } while (validity == false);
       cout << "\nPlease enter 1 for ordering another dish from the same quisine OR 2 for finishing up the order: ";
       int tried;
       cin >> tried;
       if (tried == 1)
       {
        counttillnumofdishes = 0;
       }
       else if (tried == 2)
       {
        counttillnumofdishes = 1;
       }
      } while (counttillnumofdishes == 0);

      isvalid = true;
      break;
     }
     case 5:
     {
         system("cls");
         std::cout << "88b           d88        db        88888888ba,   88888888ba         db        ad88888ba        888888888888 88888888ba         db        88 88           " << std::endl;
    std::cout << "888b         d888       d88b       88      `\"8b  88      \"8b       d88b      d8\"     \"8b            88      88      \"8b       d88b       88 88           " << std::endl;
    std::cout << "88`8b       d8'88      d8'`8b      88        `8b 88      ,8P      d8'`8b     Y8,                    88      88      ,8P      d8'`8b      88 88           " << std::endl;
    std::cout << "88 `8b     d8' 88     d8'  `8b     88         88 88aaaaaa8P'     d8'  `8b    `Y8aaaaa,              88      88aaaaaa8P'     d8'  `8b     88 88           " << std::endl;
    std::cout << "88  `8b   d8'  88    d8YaaaaY8b    88         88 88\"\"\"\"88'      d8YaaaaY8b     `\"\"\"\"\"8b,            88      88\"\"\"\"88'      d8YaaaaY8b    88 88           " << std::endl;
    std::cout << "88   `8b d8'   88   d8\"\"\"\"\"\"\"\"8b   88         8P 88    `8b     d8\"\"\"\"\"\"\"\"8b          `8b            88      88    `8b     d8\"\"\"\"\"\"\"\"8b   88 88           " << std::endl;
    std::cout << "88    `888'    88  d8'        `8b  88      .a8P  88     `8b   d8'        `8b Y8a     a8P            88      88     `8b   d8'        `8b  88 88           " << std::endl;
    std::cout << "88     `8'     88 d8'          `8b 88888888Y\"'   88      `8b d8'          `8b \"Y88888P\"             88      88      `8b d8'          `8b 88 88888888888  " << std::endl;

      cout << "\nThe South Indian dishes are as follows :-";
      cout << "\n1.}Uttappam => 200/-";
      cout << "\n2.}Idlii and sambhar => 120/-";
      cout << "\n3.}Vadaa and sambhar => 130/-";
       cout << "\n4.}Dosa and sambhar => 130/-";
        cout << "\n5.}Rasam => 130/-";
        cout << "\n6.}Pongal => 130/-";
        cout << "\n7.}Upma=> 130/-";
        cout << "\n8.}Bisi Bele Bath=> 130/-";
        cout << "\n9.}Lemon Rice => 130/-";
        cout << "\n10.}Coconut Chutneyr => 130/-";
         cout << "\n11.}Medu Vada => 200/-";
      cout << "\n12.}Masala Dosa => 120/-";
      cout << "\n13.}Appam => 130/-";
       cout << "\n14.}Pesarattu=> 130/-";
        cout << "\n15.}Avial=> 130/-";
        cout << "\n16.}Kara Kuzhambu => 130/-";
        cout << "\n17.}Thakkali Thokku=> 130/-";
        cout << "\n18.}Thakkali Thokku => 130/-";
        cout << "\n19.}Mysore Dosa => 130/-";
        cout << "\n20.}Bombard Dosa => 130/-";
      int counttillnumofdishes;
      do
      {
       cout << "\nPlease enter the index of the dish that you desire: ";
       int* choiceofdish = new int;
       int* qty = new int;
       bool validity = true;
       int arr[3] = { 200 , 120 , 130 };       //size of the array has to be altered in order to add more dishes
       do
       {
        cin >> *choiceofdish;
        if (*choiceofdish == 1)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;   //handle the error for the incorrect quantity entered.
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[0]);
         }
        }
        else if (*choiceofdish == 2)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[1]);
         }
        }
        else if (*choiceofdish == 3)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[2]);
         }
        }
        else
        {
         validity = false;
         cout << "\nPlease enter the correct choice: ";
        }
        delete qty;
        delete choiceofdish;
       } while (validity == false);
       cout << "\nPlease enter 1 for ordering another dish from the same quisine OR 2 for finishing up the order: ";
       int tried;
       cin >> tried;
       if (tried == 1)
       {
        counttillnumofdishes = 0;
       }
       else if (tried == 2)
       {
        counttillnumofdishes = 1;
       }
      } while (counttillnumofdishes == 0);

      isvalid = true;
      break;
     }
     case 6:
     {
         system("cls");
    std::cout << "88b           d88 88888888888 8b        d8 88   ,ad8888ba,        db        888b      88   ,ad8888ba,    " << std::endl;
    std::cout << "888b         d888 88           Y8,    ,8P  88  d8\"'    `\"8b      d88b       8888b     88  d8\"'    `\"8b   " << std::endl;
    std::cout << "88`8b       d8'88 88            `8b  d8'   88 d8'               d8'`8b      88 `8b    88 d8'        `8b  " << std::endl;
    std::cout << "88 `8b     d8' 88 88aaaaa         Y88P     88 88               d8'  `8b     88  `8b   88 88          88  " << std::endl;
    std::cout << "88  `8b   d8'  88 88\"\"\"\"\"         d88b     88 88              d8YaaaaY8b    88   `8b  88 88          88  " << std::endl;
    std::cout << "88   `8b d8'   88 88            ,8P  Y8,   88 Y8,            d8\"\"\"\"\"\"\"\"8b   88    `8b 88 Y8,        ,8P  " << std::endl;
    std::cout << "88    `888'    88 88           d8'    `8b  88  Y8a.    .a8P d8'        `8b  88     `8888  Y8a.    .a8P   " << std::endl;
    std::cout << "88     `8'     88 88888888888 8P        Y8 88   `\"Y8888Y\"' d8'          `8b 88      `888   `\"Y8888Y\"'    " << std::endl;

      cout << "\nThe Mexican dishes are as follows :-";
      cout << "\n1. Tacos al Pastor => Price: ₹120";
cout << "\n2. Enchiladas Suizas => Price: ₹130";
cout << "\n3. Chiles Rellenos => Price: ₹110";
cout << "\n4. Pozole => Price: ₹140";
cout << "\n5. Tamales => Price: ₹100";
cout << "\n6. Quesadillas => Price: ₹110";
cout << "\n7. Guacamole => Price: ₹120";
cout << "\n8. Fajitas => Price: ₹130";
cout << "\n9. Mole Poblano => Price: ₹150";
cout << "\n10. Carnitas => Price: ₹140";
cout << "\n11. Chilaquiles => Price: ₹130";
cout << "\n12. Sopes => Price: ₹110";
cout << "\n13. Ceviche => Price: ₹120";
cout << "\n14. Barbacoa => Price: ₹100";
cout << "\n15. Huevos Rancheros => Price: ₹140";
cout << "\n16. Tostadas => Price: ₹140";
cout << "\n17. Chile Verde => Price: ₹120";
cout << "\n18. Menudo => Price: ₹130";
cout << "\n19. Camarones a la Diabla => Price: ₹120";
cout << "\n20. Pambazos => Price: ₹150";
cout << "\n21. Flautas => Price: ₹120";
cout << "\n22. Cochinita Pibil => Price: ₹130";
cout << "\n23. Sopa de Tortilla => Price: ₹110";
cout << "\n24. Birria => Price: ₹130";
cout << "\n25. Molletes => Price: ₹120";

      int counttillnumofdishes;
      do
      {
       cout << "\nPlease enter the index of the dish that you desire: ";
       int* choiceofdish = new int;
       int* qty = new int;
       bool validity = true;
       int arr[3] = { 160 , 320 , 250 };   //this size of the array has to be changed in order to add more dishes
       do
       {
        cin >> *choiceofdish;
        if (*choiceofdish == 1)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;   //handle the error for the incorrect quantity entered.
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[0]);
         }
        }
        else if (*choiceofdish == 2)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[1]);
         }
        }
        else if (*choiceofdish == 3)
        {
         validity = true;
         cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
         cin >> *qty;
         for (int i = 0; i < *qty; i++)
         {
          s1.nums.push_back(arr[2]);
         }
        }
        else
        {
         validity = false;
         cout << "\nPlease enter the correct choice: ";
        }
        delete qty;
        delete choiceofdish;
       } while (validity == false);
       this_thread::sleep_for(chrono::seconds(4));
       system("clear");
       cout << "\nPlease enter 1 for ordering another dish from the same quisine OR 2 for finishing up the order: ";
       int tried;
       cin >> tried;
       if (tried == 1)
       {
        counttillnumofdishes = 0;
       }
       else if (tried == 2)
       {
        counttillnumofdishes = 1;
       }
      } while (counttillnumofdishes == 0);

      isvalid = true;
      break;
     }

     default:
      cout << "\nThe option that you have entered is invalid and so please enter the valid option";
      isvalid = false;
     }
    } while (isvalid == false);


    break;
   }



   else if (choice == 2)
   {
       system("cls");
    std::cout << "88888888ba  88888888888 ad88888ba 888888888888           ad88888ba  88888888888 88          88          88888888888 88888888ba   ad88888ba   " << std::endl;
    std::cout << "88      \"8b 88         d8\"     \"8b     88               d8\"     \"8b 88          88          88          88      \"8b d8\"     \"8b  " << std::endl;
    std::cout << "88      ,8P 88         Y8,             88               Y8,         88          88          88          88      ,8P Y8,          " << std::endl;
    std::cout << "88aaaaaa8P' 88aaaaa    `Y8aaaaa,       88               `Y8aaaaa,   88aaaaa     88          88          88aaaaa     88aaaaaa8P' `Y8aaaaa,  " << std::endl;
    std::cout << "88\"\"\"\"\"\"8b, 88\"\"\"\"\"      `\"\"\"\"\"8b,     88                 `\"\"\"\"\"8b, 88\"\"\"\"\"     88          88          88\"\"\"\"\"     88\"\"\"\"88'     `\"\"\"\"\"8b, " << std::endl;
    std::cout << "88      `8b 88                 `8b     88                       `8b 88          88          88          88          88    `8b           `8b  " << std::endl;
    std::cout << "88      a8P 88         Y8a     a8P     88               Y8a     a8P 88          88          88          88          88     `8b  Y8a     a8P  " << std::endl;
    std::cout << "88888888P\"  88888888888 \"Y88888P\"      88                \"Y88888P\"  88888888888 88888888888 88888888888 88      `8b  \"Y88888P\"   " << std::endl;

    tr = 1;
    cout << "\nThe following are the most ordered dishes:-";
    cout << "\nRogan josh -> ";
    cout << "\nPaneer do Pyaza -> ";
    cout << "\nMAC and CHEESE pasta -> ";
    cout << "\n Biryani =>" ;
    cout << "\n Butter Chicken (Murgh Makhani) => ";
    cout << "\n Tacos al Pastor => ";
     cout << "\n Enchiladas Suizas => ";
    cout << "\n Chiles Rellenos => ";
     cout << "\n Pozole => ";
     cout << "\n Tacos al Pastor => ";
    cout << "\n Enchiladas Suizas => ";
    cout << "\n Chiles Rellenos => ";
    cout << "\n Pozole => Price: ";
    cout << "\n Tamales => Price: ";
    break;
   }



   else if (choice == 3)
   {

    tr = 1;
       system("cls");
    std::cout << "88888888ba    ,ad8888ba,   88888888ba  88        88 88                 db        88888888ba   ad88888ba   " << std::endl;
    std::cout << "88      \"8b  d8\"'    `\"8b  88      \"8b 88        88 88                d88b       88      \"8b d8\"     \"8b  " << std::endl;
    std::cout << "88      ,8P d8'        `8b 88      ,8P 88        88 88               d8'`8b      88      ,8P Y8,          " << std::endl;
    std::cout << "88aaaaaa8P' 88          88 88aaaaaa8P' 88        88 88              d8'  `8b     88aaaaaa8P' `Y8aaaaa,    " << std::endl;
    std::cout << "88\"\"\"\"\"'   88          88 88\"\"\"\"\"\"\"   88        88 88             d8YaaaaY8b    88\"\"\"\"88'     `\"\"\"\"\"8b,  " << std::endl;
    std::cout << "88          Y8,        ,8P 88          88        88 88            d8\"\"\"\"\"\"\"8b   88    `8b           `8b  " << std::endl;
    std::cout << "88           Y8a.    .a8P  88          Y8a.    .a8P 88           d8'        `8b  88     `8b  Y8a     a8P  " << std::endl;
    std::cout << "88            `\"Y8888Y\"'   88           `\"Y8888Y\"'  88888888888 d8'          `8b 88      `8b  \"Y88888P\"   " << std::endl;
    cout << "\nThe following are the best restaurants and the restaurants that are enlisted here and are at your location";
    cout << "\nThe program needs to be run again for ordering the food";
    cout << "\nITC Mughal";
    cout << "\nHotel Amar Vilas";
    cout << "\nBarco's";
    cout << "\nCarnetic";
    cout << "\nDohful";
    cout << "\nAnna's house";
    return 0;
    break;
   }



   else
   {
    cout << "\nPlease enter a valid choice for the requirement: ";
    tr = 0;
   }
  }

  cout << "\nPlease enter 1 for ordering another dish or 2 for finishing up the order: ";
  int tried;
  cin >> tried;

  if (tried == 2)
  {
   ultimate = 1; // Set ultimate to a non-zero value to exit the outer loop
  }
  else if (tried != 1)
  {
   // Invalid input OR for continuing ordering
   cout << "\nInvalid input. Please enter 1 to order another dish or 2 to finish up the order.";
  }
 }

 cout << "\nNow the bill of the total order will be displayed: ";
 cout << "\nThe total bill is: " << bill_calculator(s1.nums);    //passing on the vector of the costs to the bill calculator function to return the total cost of the order.
string s;
 cout << "\nYou can Give feedbacks also: ";
 cin>>s;
 cout<<"/n THANK YOU VISIT AGAIN :)"<<endl;
 return 0;
}
