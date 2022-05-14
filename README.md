# Mp1_Practice_Mod
A mod focused on helping with minigame island speedruns

Features:

Display Features:</br>
Displays current main seed rng and amount of rng calls that have occurred</br>
Displays most inputs (besides L and R) pressed</br>
Displays turn count in shy guy says</br>
Displays frame count in bumper balls</br>
Displays scroll speed of camera in pipe maze as percentage</br>
Displays lag frames that have occurred at the bottom right</br>
Displays fps at bottom right</br>
</br>
Controls:</br>
While on minigame island overworld, the C-stick can advance or rollback the rng seed (also updates the calls accordingly)</br>
C-up advances the seed forwards by 1</br>
C-down advances the seed backwards by 1</br>
C-right advances the seed forwards by 16</br>
C-left advances the seed backwards by 16</br>
R resets the lag frames to 0</br>
Can toggle top left box display with L (since it can get in the way for certain minigames)</br>
</br>
While in pipe maze minigame:</br>
C-stick up/down will increase/decrease the scroll speed of the camera by 10% (default scroll speed is 150)</br>
</br>
</br>
# Building
The building process currently uses a simple batch file</br>
Follow this tutorial by shygoo for setting up armips https://hack64.net/Thread-Importing-C-Code-Into-SM64-Using-n64chain-and-armips</br>
Once armips is set up, clone this repo and create a new folder in the root of the repo named `rom`</br>
Place a vanilla, mp1 rom named `mp1.z64` in the `rom` folder</br>
Run `build.bat` and it will generate your new modded rom in the `rom` folder named `mp1.mod.z64`
