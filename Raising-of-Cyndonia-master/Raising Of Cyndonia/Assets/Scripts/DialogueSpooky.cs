using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DialogueSpooky : MonoBehaviour {

	public string dialogue;
	private DialogueManager dManager;

	// Use this for initialization
	void Start () {
		dManager = FindObjectOfType<DialogueManager> ();
	}

	// Update is called once per frame
	void Update () {

	}

	void OnTriggerEnter2D(Collider2D other)
	{
		if (other.gameObject.name == "Player") {
				dManager.ShowBox (dialogue);
		}
	}
}
