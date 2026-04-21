let emails;
const defaultEmails = [
  {
    id: crypto.randomUUID(),
    sender: "A",
    subject: "Meeting",
    body: "Lets google meet",
    read: false,
  },
  {
    id:crypto.randomUUID(),
    sender: "B",
    subject: "Happy New Year",
    body: "Congrats for new year",
    read: false,
  },
];

try {
  const stored = localStorage.getItem("emails");
  emails = stored ? JSON.parse(stored) : defaultEmails;
  if (!Array.isArray(emails)) {
  emails = defaultEmails;
}
} catch (e) {
  emails = defaultEmails;
}

let selectedId = null;

let filteredEmails = [...emails];

document.getElementById("search").addEventListener("input", (e) => {
  const q = e.target.value.toLowerCase();
  filteredEmails = emails.filter(e =>
    e.subject.toLowerCase().includes(q) ||
    e.sender.toLowerCase().includes(q)
  );
  render();
});
// render inbox
function RenderInbox() {
     
  const sidebar = document.getElementById("sidebar");
  sidebar.innerHTML = "";

if (filteredEmails.length === 0) {
  sidebar.innerHTML = "<p>No emails</p>";
}
filteredEmails.forEach((email) => {
    const div = document.createElement("div");
    div.classList.add("email");
const strong = document.createElement("strong");
strong.innerText = email.sender;

const br = document.createElement("br");

const span = document.createElement("span");
span.innerText = email.subject;

div.append(strong, br, span);

    if (email.id === selectedId) {
      div.classList.add("active");
    } else if (email.read) {
      div.classList.add("read");
    } else {
      div.classList.add("unread");
    }
    // div.innerText = email.subject;
    div.onclick = () => {
      selectedId = email.id;
  emails = emails.map(e =>
  e.id === email.id ? { ...e, read: true } : e
);
      save();
      render();
    };
    sidebar.appendChild(div);
  });
}

// Render Detail Panel
function RenderDetails() {
  const details = document.getElementById("details");
  const email = emails.find((e) => e.id === selectedId);
  if (!email) {
    details.innerHTML = `<p> Select a email </p>`;
    return;
  }
  details.innerHTML = ""; // clear

const h2 = document.createElement("h2");
h2.innerText = email.subject;

const p = document.createElement("p");
p.innerText = email.body;

const btn = document.createElement("button");
btn.innerText = "Mark as Unread";
btn.onclick = () => markUnread(email.id);

details.append(h2, p, btn);
}

function markUnread(id) {
  const email = emails.find((e) => e.id === id);
  if (!email) return;
  email.read = false;
  selectedId = null;

  save();
  render();
}

function save() {
  localStorage.setItem("emails", JSON.stringify(emails));
}

// function search(query) {
//   return emails.filter((e) => e.subject.toLowerCase().includes(query.toLowerCase()));
// }


// function deleteEmail(id) {
//     if (selectedId === id) selectedId = null;
//   emails = emails.filter((e) => e.id !== id);
//   save();
//   render();
// }


function render() {
  RenderInbox();
  RenderDetails();
}

render();

document.getElementById("composeBtn").onclick = () => {
  document.getElementById("composeBox").style.display = "block";
};

document.getElementById("send").onclick = () => {
  const newEmail = {
    id: crypto.randomUUID(),
    sender: "You",
    subject: document.getElementById("subject").value,
    body: document.getElementById("body").value,
    read: false,
  };

  emails = [newEmail, ...emails];
  filteredEmails = emails;

  save();
  render();
};

function deleteEmail(id) {
  if (!confirm("Delete this email?")) return;

  emails = emails.filter(e => e.id !== id);

  if (selectedId === id) selectedId = null;

  filteredEmails = emails;
  save();
  render();
}