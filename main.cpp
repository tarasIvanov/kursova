#include <iostream>
#include <string>

using namespace std;

struct product {
    string name;
    string category;
    int qualityOfProduct;
    double prise;
    string collor;
    string kraina;
};

struct shop {
    string name;
    int qualityOfProducts;
    product arrProducts[100];
};

int hello();

class User {
private:
    int sum = 0;
    int m = 0;
    int const sizeUserMenu = 7;
    string userList[10];
public:
    
    void showInformationOfProduct(shop & tehnik) {
        cout << endl;
        
        for (int i = 0; i < tehnik.qualityOfProducts; i++) {
            cout << i + 1 << ")" << tehnik.arrProducts[i].name << endl;
        }
        
        int infoOfProduct;
        
        while (infoOfProduct - 1 < 0 || infoOfProduct - 1 > tehnik.qualityOfProducts) {
            cout << "Введіть число продукту, про якого ви хочете подивитись детальну інформацію" << endl;
            cin >> infoOfProduct;
            
            for (int i = 0; i < tehnik.qualityOfProducts; i++) {
                if (infoOfProduct - 1 == i) {
                    cout << "Назва: " << tehnik.arrProducts[i].name << endl;
                    cout << "Категорія: " << tehnik.arrProducts[i].category << endl;
                    cout << "Кількість: " << tehnik.arrProducts[i].qualityOfProduct << endl;
                    cout << "Ціна: " << tehnik.arrProducts[i].prise << endl;
                    cout << "Колір: " << tehnik.arrProducts[i].collor << endl;
                    cout << "Країна: " << tehnik.arrProducts[i].kraina << endl;
                } else if(infoOfProduct - 1 < 0 || infoOfProduct - 1 > tehnik.qualityOfProducts){
                    cout << "Ви ввели число не з діапазону" << endl;
                    cout << "Введіть ще раз" << endl;
                }
            }
        }
    }

    void plusDoSum() {
        int plusDdoSum;
        
        cout << "\nВведіть на скільки ви хочете поповнити свій баланс" << endl;
        cin >> plusDdoSum;
        
        this->sum += plusDdoSum;
        
        cout << "Ваш баланс успішно поповнено" << endl;
        cout << "Sum: " << this->sum << endl;
    }
    
    void showUserListOfProduckts() {
        if (this->m <= 0) {
            cout << "Eror: У вас в наявності відсутні куплені продукти" << endl;
        } else {
            for (int i = 0; i < m; i++) {
                cout << i + 1 << ")" << userList[i] << endl;
            }
        }
    }
    
    void returnProduckt(shop &tehnik) {
        if (this->m <= 0) {
            cout << "Eror: У вас в наявності відсутні куплені продукти" << endl;
        } else {
            int resForReturnProduckt;
            
            for (int i = 0; i < m; i++) {
                cout << i + 1 << ")" << userList[i] << endl;
            }
            
            cout << "\nВиберіть продукт з списку" << endl;
            cin >> resForReturnProduckt;
            
            for (int i = 0; i < tehnik.qualityOfProducts; i++) {
                if (resForReturnProduckt == m) {
                    if (userList[resForReturnProduckt - 1] == tehnik.arrProducts[i].name) {
                        this->sum += tehnik.arrProducts[i].prise;
                        m--;
                        cout << "Продукт успішно повернено" << endl;
                    }
                } else if (resForReturnProduckt != m) {
                    if (userList[resForReturnProduckt - 1] == tehnik.arrProducts[i].name) {
                        this->sum += tehnik.arrProducts[i].prise;
                        this->userList[m] = tehnik.arrProducts[i].name;
                        m--;
                        cout << "Продукт успішно повернено" << endl;
                    }
                }
            }
        }
    }
    
    void showProducktList(shop &tehnik) {
        for (int i = 0; i < tehnik.qualityOfProducts; i++) {
            cout << i + 1 << ")" << tehnik.arrProducts[i].name <<  "\t" << tehnik.arrProducts[i].prise << "$" << endl;
        }
    }
    
    void byProduct(shop &tehnik) {
        int resForByProduct;
        
        for (int i = 0; i < tehnik.qualityOfProducts; i++) {
            cout << i + 1 << ")" << tehnik.arrProducts[i].name <<  "\t" << tehnik.arrProducts[i].prise << "$" << endl;
        }
        
        cout << "Exit: 0" << endl;
        
        while (true) {
            cin >> resForByProduct;
            
            if (resForByProduct == 0) {
                break;
            } else if (resForByProduct > 0 && resForByProduct <= tehnik.qualityOfProducts) {
                if (this->sum >= tehnik.arrProducts[resForByProduct - 1].prise && tehnik.arrProducts[resForByProduct - 1].qualityOfProduct != 0) {
                    this->sum -= tehnik.arrProducts[resForByProduct - 1].prise;
                    this->userList[m] = tehnik.arrProducts[resForByProduct - 1].name;
                    this->m += 1;
                    tehnik.arrProducts[resForByProduct - 1].qualityOfProduct -= 1;
                    cout << "Ви успішно придбали цей предмет" << endl;
                    cout << "Ваш залишок: " << this->sum << endl << endl;
                } else if (tehnik.arrProducts[resForByProduct - 1].qualityOfProduct == 0) {
                    cout << "Предмету нема в наявності" << endl;
                } else {
                    cout << "У вас недостатньо коштів\nПоповніть Баланс" << endl;
                    break;
                }
            } else {
                cout << endl << "Ви ввели число не з заданого діапазону\n" << endl;
            }
        }
    }
        
    void  summ() {
        cout << "Введіть кількість ваших коштів" << endl;
        cin >> this->sum;
    }
    
    int helloUser() {
        int userResult;
        
        cout << endl;
        cout << "Купити: 1" << endl;
        cout << "Повернути: 2" << endl;
        cout << "Показати лист товварі: 3" << endl;
        cout << "Показати лист куплених товарів: 4" << endl;
        cout << "Показати інформацію про продукт: 5" << endl;
        cout << "Поповнити баланс: 6" << endl;
        cout << "Книга скарг: 7" << endl;
        cout << "Вийти 0" << endl;

        cin >> userResult;
        
        if (userResult < 0 || userResult > sizeUserMenu)
            cout << "Введіть число від 1 до " << sizeUserMenu << endl;
        
        
        for (;userResult < 0 || userResult > sizeUserMenu; ) {
            cin >> userResult;
            
            if (userResult < 0 || userResult > sizeUserMenu)
                cout << "Введіть число від 1 до " << sizeUserMenu << endl;
        }
            return userResult;
    }
    
    void skargaOnShop() {
        char skargaOnShop[225];
        
        cout << "Опишіть вашу скаргу" << endl;
        cin.get(skargaOnShop, 225);
        
        cout << "Ваша скарга: " << skargaOnShop << endl;
    }
};

class Admin {
private:
    int const sizeAdminMenu = 7;
    
public:
    
    void deleteProduckt(shop &tehnik) {
        int resForDelProduckt;
        
        cout << "Видаліть будь-який продукт" << endl;
        
        for (int i = 0; i < tehnik.qualityOfProducts; i++) {
            cout << i + 1 << ")" << tehnik.arrProducts[i].name << endl;
        }
        
        cout << "Виберіть продукт якого ви хочете видалити" << endl;
        cin >> resForDelProduckt;
        
        if (tehnik.qualityOfProducts == resForDelProduckt) {
            tehnik.qualityOfProducts -= 1;
            cout << "Операцію успішно виконано" << endl;
        } else if(resForDelProduckt < tehnik.qualityOfProducts && resForDelProduckt > 0) {
            tehnik.arrProducts[resForDelProduckt - 1] = tehnik.arrProducts[tehnik.qualityOfProducts - 1];
            tehnik.qualityOfProducts -= 1;
            cout << "Операцію успішно виконано" << endl;
        } else {
            cout << "Введіть число з заданого діапазону" << endl;
        }
    }
    
    void addProduckt(shop &tehnik) {
        cout << "Створіть новий продукт" << endl;
        
        tehnik.qualityOfProducts += 1;
        
        cout << "Name: \t";                 cin >> tehnik.arrProducts[tehnik.qualityOfProducts - 1].name;
        cout << "Category: \t";             cin >> tehnik.arrProducts[tehnik.qualityOfProducts - 1].category;
        cout << "QualityOfProduct: \t";     cin >> tehnik.arrProducts[tehnik.qualityOfProducts - 1].qualityOfProduct;
        cout << "Prise: \t";                cin >> tehnik.arrProducts[tehnik.qualityOfProducts - 1].prise;
        cout << "Collor: \t";               cin >> tehnik.arrProducts[tehnik.qualityOfProducts - 1].collor;
        cout << "Kraina: \t";               cin >> tehnik.arrProducts[tehnik.qualityOfProducts - 1].kraina;
                
        cout << "Операцію успішно виконано" << endl;

    }
    
    void redacktProduckt(shop &tehnik) {
        int resFoorRedacktProduckt;
        int res2ForRedacktProduckt;
        
        cout << "Відредагуйте будь-який продукт" << endl;
        
        for (int i = 0; i < tehnik.qualityOfProducts; i++) {
            cout << i + 1 << ")" << tehnik.arrProducts[i].name <<  "\t" << tehnik.arrProducts[i].prise << "$" << endl;
        }
        
        cout << "Виберіть продукт якого ви хочете відредагувати" << endl;
        cin >> resFoorRedacktProduckt;
        
            if (resFoorRedacktProduckt > 0 && resFoorRedacktProduckt <= tehnik.qualityOfProducts) {
                cout << "Виберать що ви хочете змінити" << endl;
                
                cout << "Name: 1\t\n";
                cout << "Category: 2\t\n";
                cout << "QualityOfProduct: 3\t\n";
                cout << "Prise: 4\t\n";
                cout << "Collor: 5\t\n";
                cout << "Kraina: 6\t\n";
                cin >> res2ForRedacktProduckt;
                
                switch (res2ForRedacktProduckt) {
                    case 1:
                        cout << "Name: \t";      cin >> tehnik.arrProducts[resFoorRedacktProduckt - 1].name;
                        break;
                    case 2:
                        cout << "Category: \t";      cin >> tehnik.arrProducts[resFoorRedacktProduckt - 1].category;
                        break;
                    case 3:
                        cout << "QualityOfProduct: 3\t";     cin >> tehnik.arrProducts[resFoorRedacktProduckt - 1].qualityOfProduct;
                        break;
                    case 4:
                        cout << "Prise: 4\t";      cin >> tehnik.arrProducts[resFoorRedacktProduckt - 1].prise;
                        break;
                    case 5:
                        cout << "Collor: 5\t";      cin >> tehnik.arrProducts[resFoorRedacktProduckt - 1].collor;
                        break;
                    case 6:
                        cout << "Kraina: 6\t";     cin >> tehnik.arrProducts[resFoorRedacktProduckt - 1].kraina;
                        break;
                    default: cout << "Ви ввели число не з діапазону" << endl;
                        break;
                }
            } else {
                cout << "Ви ввели число не з діапазону" << endl;
            }
    }
    
    int helloAdmin() {
        int adminResult;
        
        cout << endl;
        cout << "Додати продукт: 1" << endl;
        cout << "Видалити продукт: 2" << endl;
        cout << "Редагувати продукт: 3" << endl;
        cout << "Показати лист товарів: 4" << endl;
        cout << "Показати інформацію про продукт: 5" << endl;
        cout << "Перехід в меню користувача 6" << endl;
        cout << "Вийти 0" << endl;

        cin >> adminResult;
        
        if (adminResult < 0 || adminResult > sizeAdminMenu)
            cout << "Введіть число від 1 до " << sizeAdminMenu << endl;
        
        for (;adminResult < 0 || adminResult > sizeAdminMenu; ) {
            cin >> adminResult;
            
            if (adminResult < 0 || adminResult > sizeAdminMenu)
                cout << "Введіть число від 1 до " << sizeAdminMenu << endl;
        }
            return adminResult;
    }
    
    void showProducktList(shop &tehnik) {
        for (int i = 0; i < tehnik.qualityOfProducts; i++) {
            cout << i + 1 << ")" << tehnik.arrProducts[i].name <<  "\t" << tehnik.arrProducts[i].prise << "$" << endl;
        }
    }
    
    void showInformationOfProduct(shop & tehnik) {
        cout << endl;
        
        for (int i = 0; i < tehnik.qualityOfProducts; i++) {
            cout << i + 1 << ")" << tehnik.arrProducts[i].name << endl;
        }
        
        int infoOfProduct;
        
        while (infoOfProduct - 1 < 0 || infoOfProduct - 1 > tehnik.qualityOfProducts) {
            cout << "Введіть число продукту, про якого ви хочете подивитись детальну інформацію" << endl;
            cin >> infoOfProduct;
            
            for (int i = 0; i < tehnik.qualityOfProducts; i++) {
                if (infoOfProduct - 1 == i) {
                    cout << "Назва: " << tehnik.arrProducts[i].name << endl;
                    cout << "Категорія: " << tehnik.arrProducts[i].category << endl;
                    cout << "Кількість: " << tehnik.arrProducts[i].qualityOfProduct << endl;
                    cout << "Ціна: " << tehnik.arrProducts[i].prise << endl;
                    cout << "Колір: " << tehnik.arrProducts[i].collor << endl;
                    cout << "Країна: " << tehnik.arrProducts[i].kraina << endl;
                } else if(infoOfProduct - 1 < 0 || infoOfProduct - 1 > tehnik.qualityOfProducts){
                    cout << "Ви ввели число не з діапазону" << endl;
                    cout << "Введіть ще раз" << endl;
                }
            }
        }
    }
};

class bigBig {
public:
    int bigBig2() {
        shop tehnik;
            tehnik.qualityOfProducts = 5;
            tehnik.name = "Super Tehnik";
            tehnik.arrProducts[0] = {"Монітор", "Техніка", 5, 200, "Червоний", "Ukraine"};
            tehnik.arrProducts[1] = {"Мишка", "Техніка", 5, 150, "Червоний", "Ukraine"};
            tehnik.arrProducts[2] = {"Клавіатура", "Техніка", 5, 200, "Червоний", "Ukraine"};
            tehnik.arrProducts[3] = {"Комп\'ютер", "Техніка", 5, 3000, "Червоний", "Ukraine"};
            tehnik.arrProducts[4] = {"Навушники", "Техніка", 5, 100, "Червоний", "Ukraine"};
        
        if (hello() == 1) {
            User user;
            user.summ();
            while (true) {
                switch (user.helloUser()) {
                    case 1:
                        user.byProduct(tehnik);
                        break;
                    case 2:
                        user.returnProduckt(tehnik);
                        break;
                    case 3:
                        user.showProducktList(tehnik);
                        break;
                    case 4:
                        user.showUserListOfProduckts();
                        break;
                    case 5:
                        user.showInformationOfProduct(tehnik);
                        break;
                    case 6:
                        user.plusDoSum();
                        break;
                    case 7:
                        user.skargaOnShop();
                        break;
                    case 0:
                        return 0;
                    default:
                        break;
                }
            }
        } else {
            Admin admin;
            while (true) {
                switch (admin.helloAdmin()) {
                    case 1:
                        admin.addProduckt(tehnik);
                        break;
                    case 2:
                        admin.deleteProduckt(tehnik);
                        break;
                    case 3:
                        admin.redacktProduckt(tehnik);
                        break;
                    case 4:
                        admin.showProducktList(tehnik);
                        break;
                    case 5:
                        admin.showInformationOfProduct(tehnik);
                        break;
                    case 6:
                        User user;
                        user.summ();
                        while (true) {
                            switch (user.helloUser()) {
                                case 1:
                                    user.byProduct(tehnik);
                                    break;
                                case 2:
                                    user.returnProduckt(tehnik);
                                    break;
                                case 3:
                                    user.showProducktList(tehnik);
                                    break;
                                case 4:
                                    user.showUserListOfProduckts();
                                    break;
                                case 5:
                                    user.showInformationOfProduct(tehnik);
                                    break;
                                case 6:
                                    user.plusDoSum();
                                    break;
                                case 7:
                                    user.skargaOnShop();
                                    break;
                                case 0:
                                    return 0;
                                default:
                                    break;
                            }
                        }
                }
            }
        }
    }
};

int main() {
    bigBig xd;
    xd.bigBig2();
    return 0;
}

int hello() {
    int whoAreYou = 0;

    cout << "Hello" << endl;
    cout << "Who are you\t 1)User ; 2)Admin" << endl;

    while (whoAreYou < 1 || whoAreYou > 2) {
        cin >> whoAreYou;
        if (whoAreYou != 1 && whoAreYou != 2) {
            cout << "Enter please 1 or 2" << endl;
        }
    }
    return whoAreYou;
}

