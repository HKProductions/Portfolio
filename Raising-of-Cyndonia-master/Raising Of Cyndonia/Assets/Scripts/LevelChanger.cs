using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using UnityEngine;

public class LevelChanger : MonoBehaviour 
{
	[SerializeField] private string loadLevel;
	void OnTriggerEnter2D (Collider2D other)
	{
		Debug.Log ("Trigger Activated! Changing Scene Now!");
		if (other.CompareTag ("Player"))
			SceneManager.LoadScene (loadLevel);
	}
}
