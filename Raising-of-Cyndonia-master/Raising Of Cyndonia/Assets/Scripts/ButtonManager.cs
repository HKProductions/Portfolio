using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using UnityEngine;

public class ButtonManager : MonoBehaviour {

	public void NewGame(string levelLoad)
	{
		SceneManager.LoadScene (levelLoad);
	}

	public void ExitGame()
	{
		Application.Quit ();
	}
		
}
