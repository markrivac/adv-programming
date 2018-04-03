using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class NavCharacter : MonoBehaviour {

	NavMeshAgent agent;
	Vector3 objetivo;

	// Use this for initialization
	void Start () {

		agent = GetComponent<NavMeshAgent> ();
		objetivo = Vector3.zero;
	}
	
	// Update is called once per frame
	void Update () {

		if(Input.GetMouseButtonUp(0)){

			Ray rayito = Camera.main.ScreenPointToRay(Input.mousePosition);
			RaycastHit hit;
			if (Physics.Raycast (rayito, out hit)) {

				objetivo = hit.point;
			}
		}

		agent.destination = objetivo;
	}
}
