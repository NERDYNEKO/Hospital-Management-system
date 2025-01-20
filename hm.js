// script.js

// Buttons
const addPatientBtn = document.getElementById("addPatientBtn");
const viewPatientsBtn = document.getElementById("viewPatientsBtn");
const addDoctorBtn = document.getElementById("addDoctorBtn");
const viewDoctorsBtn = document.getElementById("viewDoctorsBtn");

const formSection = document.getElementById("formSection");
const resultSection = document.getElementById("resultSection");

// Function to send HTTP requests
const sendRequest = async (endpoint, data = {}) => {
  try {
    const response = await fetch(endpoint, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(data),
    });
    return await response.json();
  } catch (error) {
    console.error("Error:", error);
    return { error: "Failed to communicate with the server." };
  }
};

// Event Listeners
addPatientBtn.addEventListener("click", () => {
  formSection.innerHTML = `
    <h3>Add Patient</h3>
    <form id="patientForm">
      <label>Name: <input type="text" id="patientName" required /></label><br />
      <label>Age: <input type="number" id="patientAge" required /></label><br />
      <label>Disease: <input type="text" id="patientDisease" required /></label><br />
      <label>ID: <input type="number" id="patientId" required /></label><br />
      <button type="submit">Submit</button>
    </form>`;
  formSection.classList.remove("hidden");

  document.getElementById("patientForm").onsubmit = async (e) => {
    e.preventDefault();
    const data = {
      name: document.getElementById("patientName").value,
      age: document.getElementById("patientAge").value,
      disease: document.getElementById("patientDisease").value,
      id: document.getElementById("patientId").value,
    };
    const result = await sendRequest("/addPatient", data);
    alert(result.message || "Patient added successfully!");
  };
});

// Similarly, add functionality for viewPatientsBtn, addDoctorBtn, and viewDoctorsBtn
