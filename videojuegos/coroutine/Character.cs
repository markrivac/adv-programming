using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Character : MonoBehaviour {
	
	public Node[] path;
	public float threshold;
	public Node start, end;

	private int currentNode;

	// Use this for initialization
	void Start () {
		currentNode = 0;
		StartCoroutine (HacerCambio ());

		//List<Node> breadthwise = Pathfinding.Breadthwise (start, end);
		//List<Node> depthwise = Pathfinding.Depthwise (start, end);
		List<Node> aStar = Pathfinding.AStar (start, end);

		for (int i = 0; i < aStar.Count; i++) {

			print (aStar[i].transform.name + " " + aStar[i].F);
		}
	}
	
	// Update is called once per frame
	void Update () {

		// 2 cosas en update
		// 1. input
		// 2. movimiento

		// rota el objeto de tal manera que el frente de este 
		// objeto ve al objetivo
		transform.LookAt(path[currentNode].transform);
		transform.Translate (
			transform.forward *
			Time.deltaTime * 
			5,
			Space.World
		);
	}

	IEnumerator HacerCambio(){

		while (true) {
			yield return new WaitForSeconds (0.1f);

			float distancia = Vector3.Distance (
				transform.position,
				path[currentNode].transform.position
			);

			if (distancia < threshold) {
				currentNode++;
				currentNode %= path.Length;
			}
				
		}
	}
}
