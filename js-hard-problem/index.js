async function fetchAllProfiles(ids, maxConcurrency) {
  const results = new Array(ids.length);
  let currentIndex = 0;
  let activeCount = 0;
  let completedCount = 0;

  return new Promise((resolve) => {
    function startNext() {
      // If no more items to start, check if we're done
      if (currentIndex >= ids.length) {
        // If no active tasks, we're completely finished
        if (activeCount === 0) {
          resolve(results);
        }
        return;
      }

      // Get the next id and its index
      const index = currentIndex;
      const id = ids[currentIndex];
      currentIndex++;
      activeCount++;

      // Start the async task (mock fetchProfile)
      fetchProfile(id)
        .then((data) => {
          results[index] = { id, data };
        })
        .catch((error) => {
          results[index] = { error: true, id };
        })
        .finally(() => {
          activeCount--;
          completedCount++;
          startNext(); // Start next task immediately
        });
    }

    // Start initial batch
    for (let i = 0; i < Math.min(maxConcurrency, ids.length); i++) {
      startNext();
    }
  });
}

// Mock async function (can fail randomly)
function fetchProfile(id) {
  return new Promise((resolve, reject) => {
    const delay = Math.random() * 3000 + 500; // 0.5-3.5 seconds
    setTimeout(() => {
      if (Math.random() < 0.3) {
        // 30% chance to fail
        reject(new Error(`Failed to fetch ${id}`));
      } else {
        resolve({ name: `User ${id}`, age: 20 + id });
      }
    }, delay);
  });
}

async function Abort(id, timeMillisecond = 3000) {
  const controller = new AbortController();
  const idTime = setTimeout(() => controller.abort(), timeMillisecond);
  try {
    const response = await fetchProfile(id);
    clearTimeout(idTime);
    return response;
  } catch (error) {
    if (error.name == "AbortError") {
      throw new Error(`Error millisecond = ${timeMillisecond}  and id = ${id}`);
    }

    throw error;
  }
}
// Test it
const ids = [101, 202, 303, 404, 505];
fetchAllProfiles(ids, 2 , (id) => Abort(id, 3000)).then((results) => {
  console.log(JSON.stringify(results, null, 2));
});
