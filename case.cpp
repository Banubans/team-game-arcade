#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
// Состояние игры (базовые переменные)
int hp = 100;
int resources = 50; // Деньги / Мана / Патроны / Крышки
int score = 0; // Очки выживания (цель — рекорд)
int turn = 1;
void printHUD() {
 std::cout << "\n================ [ХОД: " << turn << " | СЧЕТ: " << score
<< "] ================\n";
 std::cout << "❤️ Здоровье: " << hp << "/100 |  Ресурсы: " <<
resources << "\n";
 std::cout << "--------------------------------------------------------\n";
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
 // [РАЗРАБОТЧИК 2: ПОДКЛЮЧИТ МОДУЛЬ ОТХИЛА (ISSUE #2)]
 std::cout << "\n[!] Модуль лагеря еще в разработке (Issue#2).\n";
 break;
 case 3:
 // [РАЗРАБОТЧИК 3: ПОДКЛЮЧИТ РУЛЕТКУ/БОССА (ISSUE #3)]
 std::cout << "\n[!] Модуль событий еще в разработке (Issue#3).\n";
 break;
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
