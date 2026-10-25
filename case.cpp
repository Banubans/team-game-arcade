#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

// Состояние игры (базовые переменные)
int hp = 100;
int resources = 50; // Деньги / Мана / Патроны / Крышки
int score = 0;      // Очки выживания (цель — рекорд)
int turn = 1;

void printHUD()
{
    std::cout << "\n================ [ХОД: " << turn << " | СЧЕТ: " << score
              << "] ================\n";
    std::cout << "❤️  Здоровье: " << hp << "/100 |  Ресурсы: " << resources << "\n";
    std::cout << "--------------------------------------------------------\n ";
}
void attackBanditCamp() {
 std::cout << "\nВы отправились в рейд на лагерь бандитов...\n";
 int diceRoll = rand() % 20 + 1;
 std::cout << "Бросок к20: " << diceRoll << "\n";
 if (diceRoll >= 11) {
  int scoreReward = rand() % 301 + 200;
  int resourceReward = rand() % 31 + 20;
  score += scoreReward;
  resources += resourceReward;
  std::cout << "Победа! Вы получили " << scoreReward << " очков и "
            << resourceReward << " серебрянных монет.\n";
 } else {
  int damage = rand() % 21 + 30;
  hp -= damage;
  if (hp < 0) hp = 0;
  std::cout << "Засада! Вы потеряли " << damage << " HP.\n";
 }
}

int d20() // Бросок кубика при выборе case 3
{
    int random_number = 1 + std::rand() % 20;
    return random_number;
}

int d4() // Бросок 4-гранника
{
    int random_number = 1 + std::rand() % 4;
    return random_number;
}

int d6() // бросок кубика
{
    int random_number = 1 + std::rand() % 6;
    return random_number;
}

int d8() // бросок 8-гранника
{
    int random_number = 1 + std::rand() % 8;
    return random_number;
}

int bobr()
{
    int random_number = 1 + std::rand() % 4;
    return random_number;
}
int main() {
SetConsoleOutputCP(CP_UTF8);
SetConsoleCP(CP_UTF8);
 srand(time(NULL));
 int choice = 0;
 std::cout << ">>> ЗАПУСК СИМУЛЯЦИИ: БИТВА ЗА РЕКОРД <<<\n";
 while (hp > 0) {
 printHUD();
 std::cout << "1. Напасть на лагерь бандитов (Проверка к20)\n";
 std::cout << "2. База / Лагерь (Лечение и обмен ресурсов)\n";
 std::cout << "3. Особое событие / Рулетка удачи\n";
 std::cout << "0. Сдаться и зафиксировать счет\n";
 std::cout << "Выберите действие > ";
 if (!(std::cin >> choice)) break;
 switch (choice) {
 case 1:
 attackBanditCamp();
 break;
 case 2:
 
   std::cout << "\nВы решили разбить лагерь\n";
   std::cout << "Что хотите сделать?\n";

   std::cout << "1. Отдых\n";
   std::cout << "2. Заговорить с прохожим\n";
   std::cout << "3. Сортировка сумки\n";
   std::cout << "4. Купить зелье\n";

   int campChoice; 
    
   std::cin >> campChoice; 

    switch (campChoice) {
        case 1:
            std::cout << "Вы легли отдохнуть и восстановили силы.\n";
            std::cout << "---Востановленно 10 HP---\n";
            if (hp <= 90){
               hp += 10;
            }
            else {
               hp +=0;
            }
            break;
            
        case 2:
            std::cout << "Вы видите как к вам приближается человек в плаще.\n";
            std::cout << "Он приветствует вас и просит позволить ему отдохнуть в вашем лагере.\n";
            std::cout << "После непродолжительного общения он оскорбляется из-за вашей неудачной шутки\n";
            std::cout << "---В ходе драки вы теряете 5 hp---\n";
            hp -= 5;
            std::cout << "Незнакомец угрожает тем, что пойдёт в полицию\n";
            std::cout << "Вы откупаетесь, чтобы не нажить ещё проблем\n";
            std::cout << "---Вы потеряли 10 монет---\n";
            resources -= 10;
            break;
            
        case 3:
            std::cout << "Вы решили навести порядок в сумке.\n";
            std::cout << "Крыса пробегает между ваших ног\n";
            std::cout << "От страха вы подскакиваете\n";
            std::cout << "Чан с супом опрокидывается вам на лицо\n";
            std::cout << "---Вы теряете 40 hp---\n";
            hp -= 40;
            break;

         case 4: 
            if (hp <= 80) {
            std::cout << "Использовано: зеркало связи\n";
            std::cout << "---Потрачено 20 монет---\n";
            resources -= 20;
            std::cout << "Ваш знакомый волшебник продаёт вам зелье\n";
            std::cout << "---Употреблено зелье лечения---\n";
            std::cout << "---hp пополнено на 20 единиц---\n";
            hp += 20;
            }
            else {
               std::cout << "Вам незачем употреблять зелье";
            }
        default:
            std::cout << "Неверный пункт меню, попробуйте еще раз.\n";
            break;
    }

    break;
 



 case 3:
        {
            std::cout << "Бросьте d20 для определения случайного события.\n";
            std::cout << "Бросить кубик? Да (Y) / Нет, вернуться в главное меню (N): ";
            std::string x;
            std::cin >> x;
            if (x == "Y" || x == "y")
            {
                int x = d20();
                std::cout << "Выпало: " << x << " \n";
                std::cout << " \n";
                if (x == 1)
                {
                    std::cout << "КРИТИЧЕСКАЯ НЕУДАЧА!!! Это тоже в своём роде удача!\n";
                    std::cout << "Вы обнаружили на себе клеща, переносящего ВИЧ-инфекцию.\n";
                    std::cout << "Она очень быстро развилась, вы тяжело больны.\n";
                    std::cout << "У вас остаётся 1 хит.\n";
                    hp = 1;
                }

                if (x > 1 && x <= 7)
                {
                    std::cout << "Вы встретили злого бобра.\n";
                    // Бобр, класс брони = 14, хиты = 30.
                    /*Способности:
                    Оглушающий писк - наносит 1d4 психического урона;
                    Укус - наносит 1d6 + 60 урона
                    Удар лапой - 1 урон
                    Мультиатака - 1d8 + 2 урона*/
                    std::cout << "Он недовольно на вас смотрит.\n";
                    std::cout << "Похоже, вы бесите его только одним своим видом.\n";
                    int hp_bobr = 30;
                    int kd_bobr = 14;
                    int kd = 10 + d6() - d4();
                    while (hp_bobr > 0 && hp > 0)
                    {
                        _getch();
                        std::cout << "\n=== Ход бобра ===\n";
                        std::cout << "Бобр атакует!\n";

                        int bbr = bobr();
                        if (bbr == 1)
                        {
                            std::cout << "Бобр издаёт истошный визг\n";
                            int ur = d4();
                            hp -= ur;
                            std::cout << "Его визг пронзил ваш разум.\n";
                            std::cout << "Вам кажется, что земля уходит из-под ног, в ушах звенит\n";
                            std::cout << "Вы получаете " << ur << " психического урона.\n";
                            if (hp <= 0)
                                break;
                        }

                        else if (bbr == 2)
                        {
                            std::cout << "Бобр прыгает на вас и кусает.\n";

                            int atkRoll_bobr = d20();

                            if (atkRoll_bobr >= kd)
                            {
                                _getch();
                                int ur = d6() + 50;
                                hp -= ur;
                                std::cout << "Острые зубки Бобра впиваются в вас.\n";
                                std::cout << "Вы получаете " << ur << " урона.\n";
                                if (hp <= 0)
                                    break;
                            }

                            else
                            {
                                std::cout << "Вам удаётся увернуться от укуса!\n";
                            }
                        }
                        else if (bbr == 3)
                        {
                            std::cout << "Бобр совершает самую сильную атаку за свою короткую бобриную жизнь.\n";
                            std::cout << "От неё нельзЯ увернуться, это ЛЕГЕНДАРНОЕ ДЕЙСТВИЕ\n";
                            hp -= 1;
                            std::cout << "Вы получаете 1 урон.\n";
                            if (hp <= 0)
                                break;
                        }
                        else if (bbr == 4)
                        {
                            std::cout << "Бобр переходит в ярость и атакует мультиатакой!\n";
                            int atkRoll_bobr = d20();

                            if (atkRoll_bobr >= kd)
                            {
                                int ur = d8() + 2;
                                hp -= ur;
                                std::cout << "Серия быстрых ударов обрушивается на вас!\n";
                                std::cout << "Вы получаете " << ur << " урона.\n";
                                if (hp <= 0)
                                    break;
                            }
                            else
                            {
                                std::cout << "Вы блокируете серию ударов!\n";
                            }
                        }
                        _getch();
                        std::cout << "\n=== Ваш ход ===\n";
                        std::cout << "Ваши хиты: " << hp << " | Хиты бобра: " << hp_bobr << "\n";
                        std::cout << "1. Атаковать\n";
                        std::cout << "2. Защищаться (пропустить ход, восстановить 1d4 хитов)\n";
                        std::cout << "Выберите действие: ";

                        int choice;
                        std::cin >> choice;

                        if (choice == 1)
                        {
                            std::cout << "Вы атакуете бобра!\n";
                            int attack_roll = d20();
                            std::cout << "Бросок атаки: " << attack_roll << "\n";

                            if (attack_roll >= kd_bobr)
                            {
                                int ur = d8() + 2;
                                hp_bobr -= ur;
                                std::cout << "Попадание! Вы наносите " << ur << " урона.\n";
                            }
                            else
                            {
                                std::cout << "Промах! Бобр ловко уворачивается.\n";
                            }
                        }
                        else if (choice == 2)
                        {
                            std::cout << "Вы принимаете защитную стойку.\n";
                            _getch();
                            int heal = d4();
                            hp += heal;
                            std::cout << "Вы восстанавливаете " << heal << " хитов.\n";
                        }

                        if (hp_bobr <= 0)
                        {
                            std::cout << "\nБобр издаёт последний писк и падает замертво.\n";
                            std::cout << "Вы победили злого бобра!\n";
                            break;
                        }
                    }
                    if (x > 7 && x <= 10)
                    {
                        std::cout << "Гуляя по лесочку, вы встретили странный дуб.\n";
                        std::cout << "Он предложил сыграть в игру.\n";
                        if (resources > 0)
                        {
                            std::cout << "Играть (Y) / Уйти (N): ";
                            std::string x;
                            std::cin >> x;
                            if (x == "Y" || x == "y")
                            {
                                int chans = d20();
                                if (chans == 20)
                                {
                                    int x = d20() + 15;
                                    std::cout << "ПОБЕДА! Вы выиграли " << x << " серебряных монет\n";
                                    resources += x;
                                }

                                else if (chans >= 15)
                                {
                                    int x = d20() + 5;
                                    std::cout << "ПОБЕДА! Вы выиграли " << x << " серебряных монет\n";
                                    resources += x;
                                }

                                else if (chans > 10)
                                {
                                    int x = d8() + 5;
                                    std::cout << "ПОБЕДА! Вы выиграли " << x << " серебряных монет\n";
                                    resources += x;
                                }

                                else if (chans == 10)
                                {
                                    int x = d4();
                                    std::cout << "ПРОИГРЫШ! Вы проиграли " << x << " серебряных монет\n";
                                    if (resources >= x)
                                        resources -= x;
                                    else
                                        resources = 0;
                                }

                                else if (chans > 5)
                                {
                                    int x = d8();
                                    std::cout << "ПРОИГРЫШ! Вы проиграли " << x << " серебряных монет\n";
                                    if (resources >= x)
                                        resources -= x;
                                    else
                                        resources = 0;
                                }

                                else if (chans > 1)
                                {
                                    int x = d20();
                                    std::cout << "ПРОИГРЫШ! Вы проиграли " << x << " серебряных монет\n";
                                    if (resources >= x)
                                        resources -= x;
                                    else
                                        resources = 0;
                                }

                                else if (chans == 1)
                                {
                                    std::cout << "ПРОИГРЫШ! Вы проиграли все монеты!\n";
                                    resources = 0;
                                }
                            }
                            else if (x == "N" || x == "n")
                                break;
                            else
                                std::cout << "Выберите Y/N.\n";
                        }
                    }
                }

                if (x > 10 && x < 15)
                {
                    std::cout << "Ничего не происходит.\n";
                }

                if (x > 15 && x < 20)
                {
                    std::cout << "Прогуливаясь по лесу, вы нашли труп.\n";
                    std::cout << "Обыскав его, вы нашли зелье лечения и монеты.\n";
                    std::cout << "+10хп, +10 монет.\n";
                }

                if (x == 20)
                {
                    std::cout << "Критическая удача!! По пути вас ограбил и избил разбойник.\n";
                    std::cout << "-30 хп, -монеты.\n";
                    resources = 0;
                    hp -= 30;
                }
            }
            else if (x == "N" || x == "n")
                break;
            else
                std::cout << "Введите Y или N\n";
            break;
        }
 case 0:
 hp = 0;
 break;
 default:
 std::cout << "\nНеизвестная команда!\n";
 break;
 }
 // Каждый успешный ход дает очки выживания
 if (hp > 0) {
 turn++;
 score += 10;
 }
}
 std::cout << "\n💀 ИГРА ОКОНЧЕНА. Ваш итоговый рекорд: " << score << "очков!\n";

 return 0;

 }
