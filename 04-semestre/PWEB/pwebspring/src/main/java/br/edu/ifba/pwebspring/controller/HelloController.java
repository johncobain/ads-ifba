package br.edu.ifba.pwebspring.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import br.edu.ifba.pwebspring.model.User;

@RestController
@RequestMapping("/")
public class HelloController {
	@GetMapping
	public String HelloWorld() {
    System.out.println("Hello World");
		return "Hello World";
	}

	@GetMapping("/user")
	public User user() {
		return new User(1, "John Doe");
	}
}
