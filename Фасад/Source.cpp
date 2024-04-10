#include <iostream>
#include <string>
using namespace std;

class VideoCard {
public:
	void Start() {
		cout << "Video card starting..." << endl;
	}
	void CheckMonitor() {
		cout << "Checking connection with monitor..." << endl;
	}
	void PrintDriveInfo() {
		cout << "Printing info about reading drives..." << endl;
	}
	void PrintWinInfo() {
		cout << "Print winchester info..." << endl;
	}
	void PrintRAMInfo() {
		cout << "Print winchester info..." << endl;
	}
	void PrintLastMess() {
		cout << "Printing RAM info..." << endl;
	}
 };
class RAM {
public:
	void Start() {
		cout << "Devices starting..." << endl;
	}
	void DataAnalysis() {
		cout << "Data analysis..." << endl;
	}
	void ClearData() {
		cout << "Data clearing..." << endl;
	}
};
class Win {
public:
	void Start() {
		cout << "Winchester starting..." << endl;
	}
	void CheckLoadSector() {
		cout << "Load part checking..." << endl;
	}
	void StopDevice() {
		cout << "Stop device..." << endl;
	}
};
class ReadDrivesDevice {
public:
	void Start() {
		cout << "Read Drive Device starting..." << endl;
	}
	void CheckDrive() {
		cout << "Checking of beeing drive..." << endl;
	}
	void ReturnPos() {
		cout << "Return to start pos" << endl;
	}
};
class PowerUnit {
public:
	void Power() {
		cout << "Powering..." << endl;
	}
	void PowerVideoCard() {
		cout << "Powering Video Card..." << endl;
	}
	void PowerRAM() {
		cout << "RAM powering..." << endl;
	}
	void PowerReadDrivesDevice() {
		cout << "ReadDrivesDevice powering..." << endl;
	}
	void PowerSensors() {
		cout << "Sensors powering..." << endl;
	}
	void PowerWin() {
		cout << "Winchester powering..." << endl;
	}
	void StopPowerVideoCard() {
		cout << "Stop powering video card..." << endl;
	}
	void StopPowerRAM() {
		cout << "Stop powering RAM..." << endl;
	}
	void StopPowerWin() {
		cout << "Stop powering Winchester..." << endl;
	}
	void StopPowerReadDevice() {
		cout << "Stop powering reading device..." << endl;
	}
	void TurnOff() {
		cout << "TurnOff PowerUnit..." << endl;
	}
};
class Sensors {
public:
	void CheckPower() {
		cout << "Checking sensors power..." << endl;
	}
	void CheckPowerUnitTemp() {
		cout << "Checking PowerUnit temperature..." << endl;
	}
	void CheckVideoCardTemp() {
		cout << "Checking Video Card temperature..." << endl;
	}
	void CheckRAMTemp() {
		cout << "Checking RAM temperature..." << endl;
	}
	void CheckAllSystemsTemp() {
		cout << "Checking All Systems temperature..." << endl;
	}
};

class PCFasade {
	VideoCard videoCard;
	RAM ram;
	Win win;
	ReadDrivesDevice readdrivedevice;
	PowerUnit powerunit;
	Sensors sensors;
public:
	PCFasade(VideoCard vc, RAM rAm, Win wIn, ReadDrivesDevice rdd, PowerUnit pu, Sensors s) {
		videoCard = vc;
		ram = rAm;
		win = wIn;
		readdrivedevice = rdd;
		powerunit = pu;
		sensors = s;
	}
	void Start()
	{
		powerunit.Power();
		sensors.CheckPower();
		sensors.CheckPowerUnitTemp();
		sensors.CheckVideoCardTemp();
		powerunit.PowerVideoCard();
		videoCard.Start();
		videoCard.CheckMonitor();
		sensors.CheckRAMTemp();
		powerunit.PowerRAM();
		ram.Start();
		ram.DataAnalysis();
		videoCard.PrintRAMInfo();
		powerunit.PowerReadDrivesDevice();
		readdrivedevice.Start();
		readdrivedevice.CheckDrive();
		videoCard.PrintDriveInfo();
		powerunit.PowerWin();
		win.Start();
		win.CheckLoadSector();
		videoCard.PrintWinInfo();
		sensors.CheckAllSystemsTemp();
	}
	void Stop()
	{
		win.StopDevice();
		ram.ClearData();
		ram.DataAnalysis();
		videoCard.PrintLastMess();
		readdrivedevice.ReturnPos();
		powerunit.StopPowerVideoCard();
		powerunit.StopPowerRAM();
		powerunit.StopPowerReadDevice();
		powerunit.StopPowerWin();
		sensors.CheckPower();
		powerunit.TurnOff();
	

	}
};
class PCUser
{
public:
	void UseComputer(PCFasade facade)
	{
		facade.Start();
		facade.Stop();
	}
};

int main()
{
	VideoCard videoCard;
	RAM ram;
	Win win;
	ReadDrivesDevice readdrivedevice;
	PowerUnit powerunit;
	Sensors sensors;

	PCFasade PC1(videoCard, ram, win, readdrivedevice, powerunit, sensors);

	PCUser user1;
	user1.UseComputer(PC1);

	system("pause");
	return 0;
}