#include "stdafx.h"
#include "Database.h"
std::vector<Racer*> Database::Racer_List;
std::vector<Engine> Database::Engine_List;
std::vector<Team*> Database::Team_List;
std::vector<Race_track> Database::Track_List;
std::vector<Racer*> Database::Free_Racers_List;
int Database::points[22];

Database::Database()
{
}


Database::~Database()
{
}

void load_Engines() {
	Engine Mer(325000, 80, "Mercedes", 0, 85, Mercedes);
	Engine Fer(275000, 75, "Ferrari", 0, 80, Ferrari);
	Engine Ren(225000, 65, "Renault", 0, 75, Renault);
	Engine Hon(150000, 50, "Honda", 0, 55, Honda);
	Engine BMW(200000, 55, "BMW", 0, 75, BMW);
	Engine Toy(175000, 55, "Toyota", 0, 70, Toyota);
	Engine Cos(75000, 40, "Cosworth", 0, 80, Cosworth);
	Database::Engine_List.push_back(Mer);
	Database::Engine_List.push_back(Fer);
	Database::Engine_List.push_back(Ren);
	Database::Engine_List.push_back(Hon);
	Database::Engine_List.push_back(BMW);
	Database::Engine_List.push_back(Toy);
	Database::Engine_List.push_back(Cos);
}

void load_Racers() {
	Engine *Nico_eng = new Engine(225000, 75, "Base", 0, 75, Renault);
	Engine *Carlos_eng = new Engine(225000, 75, "Base", 0, 75, Renault);
	Engine *Fernando_eng = new Engine(150000, 65, "Base", 0, 62, Honda);
	Engine *Stoffel_eng = new Engine(150000, 65, "Base", 0, 62, Honda);
	Engine *Sebastian_eng = new Engine(275000, 80, "Base", 0, 80, Ferrari);
	Engine *Kimi_eng = new Engine(275000, 80, "Base", 0, 80, Ferrari);
	Engine *Valteri_eng = new Engine(325000, 82, "Base", 0, 85, Mercedes);
	Engine *Lewis_eng = new Engine(325000, 82, "Base", 0, 85, Mercedes);
	Engine *Daniel_eng = new Engine(225000, 75, "Base", 0, 75, Renault);
	Engine *Max_eng = new Engine(225000, 75, "Base", 0, 75, Renault);
	Engine *Sergio_eng = new Engine(325000, 79, "Base", 0, 75, Mercedes);
	Engine *Esteban_eng = new Engine(325000, 79, "Base", 0, 75, Mercedes);
	Engine *Romain_eng = new Engine(275000, 77, "Base", 0, 70, Ferrari);
	Engine *Kevin_eng = new Engine(275000, 77, "Base", 0, 70, Ferrari);
	Engine *Brendon_eng = new Engine(225000, 73, "Base", 0, 65, Renault);
	Engine *Pierre_eng = new Engine(225000, 73, "Base", 0, 65, Renault);
	Engine *Marcus_eng = new Engine(275000, 78, "Base", 0, 70, Ferrari);
	Engine *Charles_eng = new Engine(275000, 78, "Base", 0, 70, Ferrari);
	Engine *Lance_eng = new Engine(325000, 79, "Base", 0, 75, Mercedes);
	Engine *Sergey_eng = new Engine(325000, 79, "Base", 0, 75, Mercedes);
	Chassis *Ren_Cha = new Chassis(65000, 74, 65, "Base");
	Aerodynamics *Ren_Aero = new Aerodynamics(130000, 75, "Base");
	Chassis *Hon_Cha = new Chassis(45000, 69, 57, "Base");
	Aerodynamics *Hon_Aero = new Aerodynamics(140000, 78, "Base");
	Chassis *Fer_Cha = new Chassis(75000, 78, 70, "Base");
	Aerodynamics *Fer_Aero = new Aerodynamics(170000, 85, "Base");
	Chassis *Mer_Cha = new Chassis(75000, 80, 68, "Base");
	Aerodynamics *Mer_Aero = new Aerodynamics(160000, 80, "Base");
	Chassis *Red_Cha = new Chassis(70000, 78, 70, "Base");
	Aerodynamics *Red_Aero = new Aerodynamics(160000, 83, "Base");
	Chassis *For_Cha = new Chassis(60000, 72, 59, "Base");
	Aerodynamics *For_Aero = new Aerodynamics(130000, 67, "Base");
	Chassis *Haa_Cha = new Chassis(65000, 68, 68, "Base");
	Aerodynamics *Haa_Aero = new Aerodynamics(120000, 70, "Base");
	Chassis *Tor_Cha = new Chassis(60000, 65, 64, "Base");
	Aerodynamics *Tor_Aero = new Aerodynamics(120000, 66, "Base");
	Chassis *Sau_Cha = new Chassis(50000, 64, 63, "Base");
	Aerodynamics *Sau_Aero = new Aerodynamics(110000, 67, "Base");
	Chassis *Wil_Cha = new Chassis(45000, 60, 60, "Base");
	Aerodynamics *Wil_Aero = new Aerodynamics(100000, 65, "Base");
	Racer *Nico_Hul = new Racer(76, 70, 30, 2, 20000, "Nico", "Hulkenberg", Nico_eng, NULL, Ren_Cha, Ren_Aero, "", 27, "RENAULT SPORT F1 TEAM");
	Racer *Carlos_Sai=new Racer(75, 71, 23, 1, 10000, "Carlos", "Sainz", Carlos_eng, NULL, Ren_Cha, Ren_Aero, "", 55, "RENAULT SPORT F1 TEAM");
	Racer *Fernando_Alo = new Racer(75, 75, 36, 3, 35000, "Fernando", "Alonso", Fernando_eng, NULL, Hon_Cha, Hon_Aero, "", 14,"MCLAREN");
	Racer *Stoffel_Van = new Racer(67, 60, 26, 3, 5000, "Stoffel", "Vandoorne", Stoffel_eng, NULL, Hon_Cha, Hon_Aero, "", 2, "MCLAREN");
	Racer *Lewis_Ham = new Racer(85, 85, 33, 1, 120000, "Lewis", "Hamilton", Lewis_eng, NULL, Mer_Cha, Mer_Aero, "", 44, "MERCEDES");
	Racer *Valteri_Bot = new Racer(82, 77, 28, 2, 60000, "Valteri", "Bottas", Valteri_eng, NULL, Mer_Cha, Mer_Aero, "", 77, "MERCEDES");
	Racer *Daniel_Ric = new Racer(84, 78, 28, 3, 50000, "Daniel", "Ricciardo", Daniel_eng, NULL, Red_Cha, Red_Aero, "", 3, "RED BULL RACING");
	Racer *Max_Ver = new Racer(82, 85, 20, 3, 45000, "Max", "Verstappen", Max_eng, NULL, Red_Cha, Red_Aero, "", 33, "RED BULL RACING");
	Racer *Sebastian_Vet = new Racer(84, 86, 30, 2, 100000, "Sebastian", "Vettel", Sebastian_eng, NULL, Fer_Cha, Fer_Aero, "Loria", 5, "FERRARI");
	Racer *Kimi_Rai = new Racer(83, 78, 38, 3, 35000, "Kimi", "Raikonnen", Kimi_eng, NULL, Fer_Cha, Fer_Aero, "", 7, "FERRARI");
	Racer *Sergio_Per = new Racer(76, 72, 28, 2, 25000, "Sergio", "Perez", Sergio_eng, NULL, For_Cha, For_Aero, "", 11, "FORCE INDIA");
	Racer *Esteban_Occ = new Racer(73, 68, 23, 1, 10000, "Esteban", "Ocon", Esteban_eng, NULL, For_Cha, For_Aero, "", 31, "FORCE INDIA");
	Racer *Romain_Gro = new Racer(72, 70, 32, 2, 35000, "Romain", "Grosjean", Romain_eng, NULL, Haa_Cha, Haa_Aero, "", 8, "HAAS F1 TEAM");
	Racer *Kevin_Mag = new Racer(72, 69, 25, 3, 5000, "Kevin", "Magnussen", Kevin_eng, NULL, Haa_Cha, Haa_Aero, "", 20, "HAAS F1 TEAM");
	Racer *Brendon_Har = new Racer(69, 63, 28, 2, 20000, "Brendon", "Hartley", Brendon_eng, NULL, Tor_Cha, Tor_Aero, "", 28, "SCUDERIA TORO ROSSO");
	Racer *Pierre_Gas = new Racer(70, 65, 22, 3, 25000, "Pierre", "Gasly", Pierre_eng, NULL, Tor_Cha, Tor_Aero, "", 10, "SCUDERIA TORO ROSSO");
	Racer *Marcus_Eri = new Racer(67, 64, 27, 3, 35000, "Marcus", "Ericsson", Marcus_eng, NULL, Sau_Cha, Sau_Aero, "", 9, "SAUBER");
	Racer *Charles_Lec = new Racer(70, 68, 20, 3, 35000, "Charles", "Leclerc", Charles_eng, NULL, Sau_Cha, Sau_Aero, "", 16, "SAUBER");
	Racer *Lance_Str = new Racer(66, 63, 19, 3, 45000, "Lance", "Stroll", Lance_eng, NULL, Wil_Cha, Wil_Aero, "", 18, "WILLIAMS");
	Racer *Sergey_Sir = new Racer(65, 65, 22, 3, 35000, "Sergey", "Sirotkin", Sergey_eng, NULL, Wil_Cha, Wil_Aero, "", 35, "WILLIAMS");

	
	Database::Racer_List.push_back(Nico_Hul);
	Database::Racer_List.push_back(Carlos_Sai);

	Database::Racer_List.push_back(Fernando_Alo);
	Database::Racer_List.push_back(Stoffel_Van);

	Database::Racer_List.push_back(Lewis_Ham);
	Database::Racer_List.push_back(Valteri_Bot);

	Database::Racer_List.push_back(Daniel_Ric);
	Database::Racer_List.push_back(Max_Ver);

	Database::Racer_List.push_back(Sebastian_Vet);
	Database::Racer_List.push_back(Kimi_Rai);

	Database::Racer_List.push_back(Sergio_Per);
	Database::Racer_List.push_back(Esteban_Occ);

	Database::Racer_List.push_back(Romain_Gro);
	Database::Racer_List.push_back(Kevin_Mag);

	Database::Racer_List.push_back(Brendon_Har);
	Database::Racer_List.push_back(Pierre_Gas);

	Database::Racer_List.push_back(Marcus_Eri);
	Database::Racer_List.push_back(Charles_Lec);

	Database::Racer_List.push_back(Lance_Str);
	Database::Racer_List.push_back(Sergey_Sir);
}

void load_Teams() {
	Racer *temp1 = Database::Racer_List[0];
	Racer *temp2 = Database::Racer_List[1];
	Manager*Renault_man = new Manager(70, 40, 2, 15000, "Cyril", "Abiteboul");
	Team *Renault_F1_Team=new Team(temp1, temp2, "RENAULT SPORT F1 TEAM", Renault_man);
	Database::Team_List.push_back(Renault_F1_Team);
	temp1 = Database::Racer_List[2];
	temp2 = Database::Racer_List[3];
	Manager*Mclaren_man = new Manager(65, 44, 2, 15000, "Eric", "Boullier");
	Team *McLaren= new Team(temp1, temp2,"MCLAREN", Mclaren_man);
	Database::Team_List.push_back(McLaren);
	temp1 = Database::Racer_List[4];
	temp2 = Database::Racer_List[5];
	Manager*Mercedes_man = new Manager(85, 46, 2, 15000, "Toto", "Wolff");
	Team *Mercedes_team = new Team(temp1, temp2,"MERCEDES", Mercedes_man);
	Database::Team_List.push_back(Mercedes_team);
	temp1 = Database::Racer_List[6];
	temp2 = Database::Racer_List[7];
	Manager*Red_bull_man = new Manager(75, 44, 2, 15000, "Christian", "Horner");
	Team *Redbull_team = new Team(temp1, temp2, "RED BULL RACING", Red_bull_man);
	Database::Team_List.push_back(Redbull_team);
	temp1 = Database::Racer_List[8];
	temp2 = Database::Racer_List[9];
	Manager*Ferrari_man = new Manager(80, 61, 2, 15000, "Maurizio", "Arrivabene");
	Team *Ferrari_team = new Team(temp1, temp2, "FERRARI", Ferrari_man);
	Database::Team_List.push_back(Ferrari_team);
	temp1 = Database::Racer_List[10];
	temp2 = Database::Racer_List[11];
	Manager*Force_man = new Manager(60, 62, 2, 15000, "Vijay", "Mallya");
	Team *Force_india_team = new Team(temp1, temp2, "FORCE INDIA", Force_man);
	Database::Team_List.push_back(Force_india_team);
	temp1 = Database::Racer_List[12];
	temp2 = Database::Racer_List[13];
	Manager*Haas_man = new Manager(55,53 , 2, 15000, "Guenther", "Steiner");
	Team *Haas_team = new Team(temp1, temp2, "HAAS F1 TEAM", Haas_man);
	Database::Team_List.push_back(Haas_team);
	temp1 = Database::Racer_List[14];
	temp2 = Database::Racer_List[15];
	Manager*Toro_man = new Manager(70, 62, 2, 15000, "Franz", "Tost");
	Team *Toro_rosso_team = new Team(temp1, temp2, "SCUDERIA TORO ROSSO", Toro_man);
	Database::Team_List.push_back(Toro_rosso_team);
	temp1 = Database::Racer_List[16];
	temp2 = Database::Racer_List[17];
	Manager*Sauber_man = new Manager(65, 50, 2, 15000, "Frédéric", "Vasseur");
	Team *Sauber_team = new Team(temp1, temp2, "SAUBER", Sauber_man);
	Database::Team_List.push_back(Sauber_team);
	temp1 = Database::Racer_List[18];
	temp2 = Database::Racer_List[19];
	Manager*Williams_man = new Manager(75, 56, 2, 15000, "Paddy", "Lowe");
	Team *Williams_team = new Team(temp1, temp2, "WILLIAMS",Williams_man);
	Database::Team_List.push_back(Williams_team);
}
void load_tracks() {
	Race_track Melbourne("Albert Park, Melbourne", 70, 50, 30, 20, 58, 90000, Hypersoft, Ultrasoft, Supersoft, 1);
	Race_track Shanghai("Shanghai International Circuit", 60, 70, 60, 40, 56, 100000, Supersoft, Soft, Medium, 2);
	Database::Track_List.push_back(Melbourne);
	Database::Track_List.push_back(Shanghai);
}
void load_points() {
	Database::points[0] = 25;
	Database::points[1] = 18;
	Database::points[2] = 15;
	Database::points[3] = 12;
	Database::points[4] = 10;
	Database::points[5] = 8;
	Database::points[6] = 6;
	Database::points[7] = 4;
	Database::points[8] = 2;
	Database::points[9] = 1;
	for (int i = 10; i < 22; i++) {
		Database::points[i] = 0;
	}
}

void load_free_Racers() {
	Racer *Paul_Di = new Racer(65, 70, 30, 2, 10000, "Paul", "Di Resta", NULL, NULL, NULL, NULL, "", 99, "Free");
	Racer *Robert_Kubica = new Racer(85, 80, 33, 1, 100000, "Robert", "Kubica",  NULL, NULL, NULL, NULL, "", 45, "Free");
	Racer *Rubens_Bar = new Racer(75, 69, 36, 3, 55000, "Rubens", "Barrichello", NULL, NULL, NULL, NULL, "", 66, "Free");
	Racer *Nick_Hei = new Racer(70, 70, 41, 3, 35000, "Nick", "Heifeld", NULL, NULL, NULL, NULL, "", 15, "Free");
	Racer *Bruno_Sen = new Racer(60, 65, 34, 1, 5000, "Bruno", "Senna", NULL, NULL, NULL, NULL, "", 71, "Free");
	Database::Free_Racers_List.push_back(Bruno_Sen);
	Database::Free_Racers_List.push_back(Paul_Di);
	Database::Free_Racers_List.push_back(Nick_Hei);
	Database::Free_Racers_List.push_back(Rubens_Bar);
	Database::Free_Racers_List.push_back(Robert_Kubica);
}