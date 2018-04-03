using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DemoAI : MonoBehaviour {

	public float distanciaLimite;
	public Transform enemigo;

	private AINode nodoActual;
	private AINode nodoAnterior;
	// SÍMBOLOS
	AISymbol verEnemigo;
	AISymbol serAtacado;
	AISymbol vidaCero;
	AISymbol staminaCero;
	private MonoBehaviour behaviour;

	// Use this for initialization
	void Start () {

		//	modelando comportamiento de un soldado
		AINode cubriendo = new AINode ("Cubriendo", typeof(CubiertoBehaviour));
		AINode durmiendo = new AINode ("Durmiendo", typeof(DormirBehaviour));
		AINode muerto = new AINode ("Morido", typeof(MorirBehaviour));
		AINode atacando = new AINode("Atacando", typeof(AtacarBehaviour));

		// SÍMBOLOS
		verEnemigo = new AISymbol("ver enemigo");
		serAtacado = new AISymbol("ser atacado");
		vidaCero = new AISymbol("vida cero");
		staminaCero = new AISymbol("stamina cero");

		//ESTADO INICIAL
		nodoActual = cubriendo;
		nodoAnterior = null;
		behaviour = (MonoBehaviour)gameObject.AddComponent(nodoActual.Behaviour);

		//FUNCIÓN DE TRANSICIÓN
		atacando.AddTransition (verEnemigo, cubriendo);
		atacando.AddTransition (serAtacado, cubriendo);
		atacando.AddTransition (vidaCero, muerto);
		atacando.AddTransition (staminaCero, muerto);

		cubriendo.AddTransition (verEnemigo, atacando);
		cubriendo.AddTransition (serAtacado, durmiendo);
		cubriendo.AddTransition (vidaCero, muerto);
		cubriendo.AddTransition (staminaCero, durmiendo);

		durmiendo.AddTransition (verEnemigo, cubriendo);
		durmiendo.AddTransition (serAtacado, muerto);
		durmiendo.AddTransition (vidaCero, muerto);
		durmiendo.AddTransition (staminaCero, muerto);

		muerto.AddTransition (verEnemigo, muerto);
		muerto.AddTransition (serAtacado, muerto);
		muerto.AddTransition (vidaCero, muerto);
		muerto.AddTransition (staminaCero, muerto);
	}
	
	// Update is called once per frame
	void Update () {

		if (Input.GetKeyUp (KeyCode.A)) {
			ApplyTransition (verEnemigo);
			print (nodoActual.Name);
		}
		if (Input.GetKeyUp (KeyCode.S)) {
			ApplyTransition (serAtacado);
			print (nodoActual.Name);
		}
		if (Input.GetKeyUp (KeyCode.D)) {
			ApplyTransition (vidaCero);
			print (nodoActual.Name);
		}
		if (Input.GetKeyUp (KeyCode.F)) {
			ApplyTransition (staminaCero);
			print (nodoActual.Name);
		}
	}

	void ApplyTransition(AISymbol symbol){
		nodoActual = nodoActual.ApplyTransition (symbol);
		if (nodoActual != nodoAnterior) {
			Destroy (behaviour);
			behaviour = (MonoBehaviour)gameObject.AddComponent (nodoActual.Behaviour);
		}
		nodoAnterior = nodoActual;
	}

	IEnumerator RevisarDistancia(){

		while (true) {

			float distancia = Vector3.Distance (transform.position, enemigo.position);
			if (distancia < distanciaLimite) {
				ApplyTransition (serAtacado);
			}

			yield return new WaitForSeconds (0.5f);
		}

	}
}
